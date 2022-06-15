#include <iostream>
#include <stdio.h>
#include <Simple_PARAMETER_EDITOR.h>
#include <Simple_patternedAI_Array.h>
#include <Simple_Enemy_Offset_Locations.h>
#include <fstream>
#include <string>
#include <sstream>
#include <random>
//#include <cstdint>
//#include <cctype>
//using namespace std;

std::random_device rd;
std::fstream input;
std::fstream output;
std::mt19937 gen;

int main()
{
    new PARAMETEREDITOR();
    return 0;
}

PARAMETEREDITOR::PARAMETEREDITOR()
{
    gen.seed(601310422);
    scaleLow = 0.25;
    scaleHigh = 4;
    healthLow = 0.25;
    healthHigh = 4;
    speedLow = 0.25;
    speedHigh = 4;
    damageLow = 0.25;
    damageHigh = 4;
    knockbackPowerLow = 0.25;
    knockbackPowerHigh = 4;
    randoScaleSeperate = true;
    inputLocation = "C:/Users/nevin/Documents/Dolphin-x64/Games/Metroid Prime (USA) (v1.00).iso";
    //outputLocation = "C:/Users/nevin/Documents/Dolphin-x64/Games/M.iso";
    input.open(inputLocation, std::ios::in | std::ios::out | std::ios::binary | std::ios::ate);
    //output.open(outputLocation, std::ios::in | std::ios::out | std::ios::binary | std::ios::ate);
    PARAMETEREDITOR::Simple_PARAMETER_EDITOR();
}

PARAMETEREDITOR::PARAMETEREDITOR(string in_File, string out_File, int gen_Seed, float SCALE_L, float SCALE_H, float HEALTH_L, float HEALTH_H, float SPEED_L, float SPEED_H, float DAMAGE_L, float DAMAGE_H, float KNOCK_L, float KNOCK_H, bool Seperate)
{
    inputLocation = in_File;
    outputLocation = out_File;
    scaleLow = SCALE_L;
    scaleHigh = SCALE_H;
    healthLow = HEALTH_L;
    healthHigh = HEALTH_H;
    speedLow = SPEED_L;
    speedHigh = SPEED_H;
    damageLow = DAMAGE_L;
    damageHigh = DAMAGE_H;
    knockbackPowerLow = KNOCK_L;
    knockbackPowerHigh = KNOCK_H;
    randoScaleSeperate = Seperate;
    gen.seed(gen_Seed);

    input.open(inputLocation, std::ios::in | std::ios::out | std::ios::binary | std::ios::ate);
    output.open(outputLocation, std::ios::in | std::ios::out | std::ios::binary | std::ios::ate);

    if (output.is_open())
    {
        PARAMETEREDITOR::Simple_PARAMETER_EDITOR();
    }
    else
    {
        cout << "Couldn't find output file.\n" << endl;
    }
}

void PARAMETEREDITOR::Simple_PARAMETER_EDITOR()
{
    if (input.is_open())
    {
        PARAMETEREDITOR::enemy_Param_Editor();
    }
    else
    {
        cout << "Couldn't find input file.\n" << endl;
    }
}

int PARAMETEREDITOR::return_Data(unsigned int hex_Data, bool small_Value)
{
    if (input.is_open())
    {
        char data[4];
        input.seekg(hex_Data);
        input.read(data, (std::ifstream::pos_type)4);
        if (small_Value)
        {
            return (unsigned char)data[0];
        }
  
        unsigned int hex_Value1 = (unsigned char)data[0];
        unsigned int hex_Value2 = (unsigned char)data[1];
        unsigned int hex_Value3 = (unsigned char)data[2];
        unsigned int hex_Value4 = (unsigned char)data[3];

        int offset = PARAMETEREDITOR::combine(hex_Value1, hex_Value2, hex_Value3, hex_Value4);
        return offset;

    }
    else 
    {
        std::cout << "Unable to open file\n" << endl;
        exit(0);
    }

}
int PARAMETEREDITOR::combine(int a, int b, int c, int d)
{
    char hex_string1[4];
    char hex_string2[4];
    char hex_string3[4];
    char hex_string4[4];

    
    sprintf_s(hex_string1, "%X", a);
    sprintf_s(hex_string2, "%X", b);
    sprintf_s(hex_string3, "%X", c);
    sprintf_s(hex_string4, "%X", d);

    std::string str1(hex_string1);
    std::string str2(hex_string2);
    std::string str3(hex_string3);
    std::string str4(hex_string4);


if (a < 0x10)
{
    str1 = ("0" + str1);
}
if (b < 0x10)
{
    str2 = ("0" + str2);
}
if (c < 0x10)
{
    str3 = ("0" + str3);
}
if (d < 0x10)
{
    str4 = ("0" + str4);
}


std::string string_result = str1 + str2 + str3 + str4;
unsigned int int_result;
std::stringstream ss;
ss << std::hex << string_result;
ss >> int_result;

return int_result;

}


void PARAMETEREDITOR::enemy_Param_Editor()
{
    float randomized_Value = 0;


    for (unsigned int i = 0; i < 40; i++)
    {
        for (unsigned int o = 1; o < EnemyOffsets[i][0]; o++)
        {
            for (unsigned int c = 0; c < 6; c++)
            {
                switch (c)
                {
                case 0:
                    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
                    break;
                case 1:
                    randomized_Value = PARAMETEREDITOR::randomFloat(healthLow, healthHigh);
                    break;
                case 2:
                    randomized_Value = PARAMETEREDITOR::randomFloat(speedLow, speedHigh);
                    break;
                case 3:
                    break;
                case 4:
                    randomized_Value = PARAMETEREDITOR::randomFloat(damageLow, damageHigh);
                    break;
                case 5:
                    randomized_Value = PARAMETEREDITOR::randomFloat(knockbackPowerLow, knockbackPowerHigh);
                    break;
                default:
                    std::cout << "Something went wrong\n" << std::endl;
                    exit(1);
                }

                unsigned int enemy_Data_Size;

                if (i < 27)
                {
                    enemy_Data_Size = EnemyInfo[i][c][0];
                }
                else
                {
                    enemy_Data_Size = 0;
                }
                if (enemy_Data_Size != 0x000)
                {
                    for (unsigned int e = 1; e < enemy_Data_Size; e++)
                    {
                        if (c == 0 && randoScaleSeperate == true)
                        {
                            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
                        }
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], randomized_Value, EnemyInfo[i][c][e], c, i);
                    }
                }
                if (i < 37)
                {
                    enemy_Data_Size = PatternedAI[c][0];
                }
                else
                {
                    enemy_Data_Size = 0;
                }
                if (enemy_Data_Size != 0x000)
                {
                    for (unsigned int e = 1; e < enemy_Data_Size; e++)
                    {
                        if ((c == 0 && randoScaleSeperate == true) && (EnemyOffsets[i][o] != 0x53411AAD || EnemyOffsets[i][o] != 0x53411D44 || EnemyOffsets[i][o] != 0x53411821))
                        {
                            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
                        }
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], randomized_Value, PatternedAI[c][e], c, i);
                        if (EnemyOffsets[i][o] == 0x3c40a252)
                        {
                            if (c == 0)
                            {
                                switch (e)
                                {
                                case 1:
                                    for (int armor = 0; armor < 4; armor++)
                                    {
                                        PARAMETEREDITOR::write_Data(OmegaPirateArmorScaleOffset[armor], randomized_Value, 0x0, c, 0xFF);
                                    }
                                    for (int omega = 0; omega < 24; omega++)
                                    {
                                        PARAMETEREDITOR::write_Data(OmegaPirateArmorEffectOffset[omega], randomized_Value, 0x0, c, 0xFF);
                                    }
                                    break;
                                case 2:
                                    for (int armor = 0; armor < 4; armor++)
                                    {
                                        PARAMETEREDITOR::write_Data(OmegaPirateArmorScaleOffset[armor], randomized_Value, 0x4, c, 0xFF);
                                    }
                                    for (int omega = 0; omega < 24; omega++)
                                    {
                                        PARAMETEREDITOR::write_Data(OmegaPirateArmorEffectOffset[omega], randomized_Value, 0x4, c, 0xFF);
                                    }
                                    break;
                                case 3:
                                    for (int armor = 0; armor < 4; armor++)
                                    {
                                        PARAMETEREDITOR::write_Data(OmegaPirateArmorScaleOffset[armor], randomized_Value, 0x8, c, 0xFF);
                                    }
                                    for (int omega = 0; omega < 24; omega++)
                                    {
                                        PARAMETEREDITOR::write_Data(OmegaPirateArmorEffectOffset[omega], randomized_Value, 0x8, c, 0xFF);
                                    }
                                    break;
                                default:
                                    std::cout << "something went wrong\n" << std::endl;
                                    exit(1);
                                }
                            }
                            else if (c == 1 && e == 1)
                            {
                                PARAMETEREDITOR::write_Data(0x3C40B163, randomized_Value, 0x0, c, 0xFF);
                                PARAMETEREDITOR::write_Data(0x3C40B368, randomized_Value, 0x0, c, 0xFF);
                                PARAMETEREDITOR::write_Data(0x3C40B568, randomized_Value, 0x0, c, 0xFF);
                                PARAMETEREDITOR::write_Data(0x3C40B75C, randomized_Value, 0x0, c, 0xFF);
                            }
                        }
                    }
                }
                else if (i == 37)
                {
                    enemy_Data_Size = Turret[c][0];
                    for (unsigned int e = 1; e < enemy_Data_Size; e += 1)
                    {
                        if (c == 0 && randoScaleSeperate == true)
                        {
                            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
                        }
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], randomized_Value, Turret[c][e], c, i);
                    }
                }
                else if (i == 38)
                {
                    enemy_Data_Size = AmbientAI[c][0];
                    for (unsigned int e = 1; e < enemy_Data_Size; e++)
                    {
                        if (c == 0 && randoScaleSeperate == true)
                        {
                            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
                        }
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], randomized_Value, AmbientAI[c][e], c, i);
                    }
                }
                else if (i == 39)
                {
                    enemy_Data_Size = Swarm[c][0];
                    for (unsigned int e = 1; e < enemy_Data_Size; e++)
                    {
                        if (c == 0 && randoScaleSeperate == true)
                        {
                            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
                        }
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], randomized_Value, Swarm[c][e], c, i);
                    }
                }
                else if (i == 40)
                {
                    enemy_Data_Size = EnemyOffsets[i][0];
                    while (o < enemy_Data_Size)
                    {
                        randomized_Value = PARAMETEREDITOR::randomFloat(1, 4);
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], randomized_Value, 0x0, c, i);
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], randomized_Value, 0x10, c, i);
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], randomized_Value, 0x18, c, i);
                        o++;
                    }
                    break;
                }
            }
        }
    }
}

void PARAMETEREDITOR::write_Data(unsigned int current_Offset, float randomized_Value, unsigned int offset, unsigned int conditional, int ID)
{
    //if (offset != 0x000)
    if (true)
    {
        if (ID == 1 || ID == 4 || ID == 6 || ID == 12 || ID == 13 || ID == 21 || ID == 27 || ID == 28 || ID == 29 || ID == 34 || ID == 37)
        {
            offset += 0x4;
            if (ID == 4 && conditional != 0)
            {
                offset += 0x4;
            }
        }
        while ((ID == 23 || ID == 24) && conditional == 0 && randomized_Value > static_cast<float>(3))
        {
            if (scaleLow == scaleHigh)
            {
                randomized_Value = static_cast<float>(3);
                break;
            }
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
        if (ID == 22 && conditional == 1)
        {
            return;
        }
        if (ID == 9 || ID == 16 || ID == 5 || ID == 21 || ID == 25)
        {
            if (conditional == 0x0)
            {
                return;
            }
        }
        if ((ID == 25 || ID == 3 || ID == 6 || ID == 21 || ID == 24) && (conditional == 2 || conditional == 3))
        {
            return;
        }
        while (ID == 3 && (conditional == 2 || conditional == 3) && randomized_Value > 2)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(speedLow, speedHigh);
        }

        unsigned int value = PARAMETEREDITOR::return_Data(current_Offset + offset, false);
        float* pp = (float*)&value;
        if (conditional == 3)
        {
            (*pp) /= randomized_Value;
        }
        else
        {
            (*pp) *= randomized_Value;
        }
        if (output.is_open())
        {
            output.seekp(current_Offset + offset);
        }
        else if (input.is_open())
        {
            input.seekp(current_Offset + offset);
        }
        unsigned char* address = (unsigned char*) & value;
        unsigned char c0 = address[0];
        unsigned char c1 = address[1];
        unsigned char c2 = address[2];
        unsigned char c3 = address[3];
        address[0] = c3;
        address[1] = c2;
        address[2] = c1;
        address[3] = c0;
        if (output.is_open())
        {
            output.write((char*)&value, 4);
        }
        else if (input.is_open())
        {
            input.write((char*)&value, 4);
        }
    }
}

float PARAMETEREDITOR::randomFloat(float low, float high)
{
    if (low == high)
    {
        return high;
    }
    
    std::uniform_real_distribution<> RNG(low, high);

    //cout << RNG(gen) << endl;

    return RNG(gen);
}