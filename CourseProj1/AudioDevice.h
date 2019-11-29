#ifndef _AUDIODEVICE_H
#define _AUDIODEVICE_H

#include <al.h>
#include <alc.h>
#include "Camera.h"

class AudioDevice
{
	struct SoundData
	{
		int sourceID, bufferID;
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
		bool IsBigEndian();
		char* LoadWave(const char* filename, int& channel, int& samplerate, int& bps, int& size);
		static AudioDevice* instance;
		ALCcontext* context;
		ALCdevice* device;
		vector<SoundData> datas;


};

#endif