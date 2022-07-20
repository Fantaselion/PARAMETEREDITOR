#pragma once
#include <fstream>


using namespace std;


class PARAMETEREDITOR
{

public:

	PARAMETEREDITOR();
	PARAMETEREDITOR(string in_File, string out_File, int gen_Seed, float SCALE_L, float SCALE_H, float HEALTH_L, float HEALTH_H, float SPEED_L, float SPEED_H, float DAMAGE_L, float DAMAGE_H, float KNOCK_L, float KNOCK_H, bool Seperate);
	void start_Here();
	int return_Data(unsigned int hex_Data, bool small_Value);
	void find_Pointer_Size(unsigned int Pointer);
	static uint32_t ReverseBytes(uint32_t value);
	void MREA_SEARCH(unsigned int current_Offset, unsigned int size);
	void SCLY_SEARCH(unsigned int current_Offset);
	void enemy_Param_Searcher(unsigned int current_Offset, unsigned int size);
	void enemy_Start_Of_Attributes(unsigned int current_Offset, unsigned int data_Size, unsigned int object_ID_Element);
	void enemy_Param_Editor();
	void write_Data(unsigned int current_Offset, unsigned int offset, unsigned int conditional, int ID, bool small_Value, unsigned int offset_Position = 0xFFFF);
	float randomFloat(float low, float high);
	void add_Offsets_To_Vector(unsigned int current_Offset, int o);
	bool garbage = false;
	float scaleLow;
	float scaleHigh;
	float healthLow;
	float healthHigh;
	float speedLow;
	float speedHigh;
	float damageLow;
	float damageHigh;
	float knockbackPowerLow;
	float knockbackPowerHigh;
	bool randoScaleSeperate;
	string inputLocation;
	string outputLocation;
	int times = 0;
	int cur_Pak = 0;
};