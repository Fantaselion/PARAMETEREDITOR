#pragma once

using namespace std;

class PARAMETEREDITOR
{

public:

	PARAMETEREDITOR();
	PARAMETEREDITOR(string in_File, string out_File, int gen_Seed, float SCALE_L, float SCALE_H, float HEALTH_L, float HEALTH_H, float SPEED_L, float SPEED_H, float DAMAGE_L, float DAMAGE_H, float KNOCK_L, float KNOCK_H, bool Seperate);
	void Simple_PARAMETER_EDITOR();
	int return_Data(unsigned int hex_Data, bool small_Value);
	void enemy_Param_Editor();
	void write_Data(unsigned int current_offset, float randomized_Value, unsigned int offset, unsigned int conditional, int object_ID);
	int combine(int a, int b, int c, int d);
	float randomFloat(float low, float high);
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

};