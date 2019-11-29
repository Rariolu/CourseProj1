#include "AudioDevice.h"

AudioDevice* AudioDevice::instance = nullptr;

AudioDevice::AudioDevice()
{
	device = alcOpenDevice(nullptr);
	if (!device)
	{
		//error message
	}
	context = alcCreateContext(device, nullptr);
	if (!context)
	{
		//error message
	}
	alcMakeContextCurrent(context);
}

AudioDevice::~AudioDevice()
{
	for (unsigned int i = 0; i < datas.size(); i++)
	{
		alDeleteSources(1, (unsigned int*)& datas[i].sourceID);
		if (datas[i].bufferID != -1)
		{
			DeleteSound(datas[i].bufferID);
		}
	}
	alcDestroyContext(context);
	alcCloseDevice(device);
}

AudioDevice* AudioDevice::Instance()
{
	if (!instance)
	{
		return instance = new AudioDevice();
	}
	return instance;
}

unsigned int AudioDevice::LoadSound(const char* filename)
{
	bool found = false;
	unsigned int sourceID;
	unsigned int bufferID;
	for (unsigned int i = 0; i < datas.size(); i++)
	{
		if (datas[i].filename == filename && datas[i].bufferID != -1)
		{
			bufferID = datas[i].bufferID;
			found = true;
			break;
		}
	}
	if (!found)
	{
		char* soundData = nullptr;
		int channel, sampleRate, bps, size;
		soundData = LoadWave(filename, channel, sampleRate, bps, size);
		unsigned int format;
		alGenBuffers(1, &bufferID);

		if (channel == 1)
		{
			if (bps == 8)
			{
				format = AL_FORMAT_MONO8;
			}
			else
			{
				format = AL_FORMAT_MONO16;
			}
		}
		else
		{
			if (bps == 8)
			{
				format = AL_FORMAT_STEREO8;
			}
			else
			{
				format = AL_FORMAT_STEREO16;
			}
		}

		alBufferData(bufferID, format, soundData, size, sampleRate);
	}
	alGenSources(1, &sourceID);
	alSourcei(sourceID, AL_BUFFER, bufferID);
	alSourcef(sourceID, AL_REFERENCE_DISTANCE, 1.0f);
	SoundData sd = SoundData(sourceID, !found ? bufferID : -1, filename);
	datas.push_back(sd);
	return sourceID;
}

void AudioDevice::PlaySound(unsigned int id)
{
	alSourcePlay(id);
}

void AudioDevice::PlaySound(unsigned int id, Vec3 pos)
{
	alSource3f(id, AL_POSITION, pos.x, pos.y, pos.z);
	PlaySound(id);
}

void AudioDevice::SetListener(Camera* camera)
{
	Vec3 pos = *camera->GetPosition();
	Vec3 dir = *camera->GetForward();
	alListener3f(AL_POSITION, pos.x, pos.y, -pos.z);
	float orinet[6] = { dir.x, dir.y, dir.z,0,1,0 };
	alListenerfv(AL_ORIENTATION, orinet);
}

void AudioDevice::StopSound(unsigned int id)
{
	alSourceStop(id);
}

int AudioDevice::ConvertToInt(char* buffer, int length)
{
	int a = 0;
	if (IsBigEndian())
	{
		for (int i = 0; i < length; i++)
		{
			((char*)& a)[3 - i] = buffer[i];
		}
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			((char*)& a)[i] = buffer[i];
		}
	}
	return a;
}

void AudioDevice::DeleteSound(unsigned int id)
{
	alDeleteBuffers(1, (unsigned int*)& id);
}

bool AudioDevice::IsBigEndian()
{
	int a = 1;
	return !((char*)& a)[0];
}

char* AudioDevice::LoadWave(const char* filename, int& channel, int& samplerate, int& bps, int& size)
{
	char buffer[4];
	InputFileStream in(filename, std::ios::binary);
	in.read(buffer, 4);
	in.read(buffer, 4);
	in.read(buffer, 4); //WAV
	in.read(buffer, 4);	//fmt
	in.read(buffer, 4); //16 bit
	in.read(buffer, 2); //1
	in.read(buffer, 2);
	channel = ConvertToInt(buffer, 2);
	in.read(buffer, 4);
	samplerate = ConvertToInt(buffer, 4);
	in.read(buffer, 4);
	in.read(buffer, 2);
	in.read(buffer, 2);
	bps = ConvertToInt(buffer, 2);
	in.read(buffer, 4);
	in.read(buffer, 4);
	size = ConvertToInt(buffer, 4);

	char* soundData = new char[size];
	in.read(soundData, size);
	return soundData;
}