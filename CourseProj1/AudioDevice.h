#ifndef _AUDIODEVICE_H
#define _AUDIODEVICE_H

#include <al.h>
#include <alc.h>
#include "Camera.h"

//Establishes a connection to the primary audio device
//and allows audio to be played using it.
class AudioDevice
{
	//Represents a particular instantiation of an
	//an audio file (uniquely identified by the "bufferID"
	//(the ID of the audio itself) and the "sourceID" (the
	//ID of the particular in-world source).
	struct SoundData
	{
		int bufferID;
		int sourceID;
		const char* filename;
		SoundData(unsigned int sI, unsigned int bI, const char* n)
		{
			sourceID = sI;
			bufferID = bI;
			filename = n;
		}
	};
	public:
		static AudioDevice* Instance();
		~AudioDevice();
		unsigned int LoadSound(const char* filename);
		void PlaySound(unsigned int id);
		void PlaySound(unsigned int id, Vec3 pos);
		void SetListener(Camera* camera);
		void StopSound(unsigned int id);
	private:
		AudioDevice();
		int ConvertToInt(char* buffer, int length);
		void DeleteSound(unsigned int id);
		char* LoadWave(const char* filename, int& channel, int& samplerate, int& bps, int& size);
		void SetIsBigEndian();
		static AudioDevice* instance;
		ALCcontext* context;
		ALCdevice* device;
		vector<SoundData> datas;
		bool isBigEndian;
};

#endif