#include <iostream>
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

float ElitePirateRando;
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
    gen.seed(rd());
    scaleLow = 0.05;
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

    
    sprintf(hex_string1, "%X", a);
    sprintf(hex_string2, "%X", b);
    sprintf(hex_string3, "%X", c);
    sprintf(hex_string4, "%X", d);

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


    for (unsigned int i = 0; i < 42; i++)
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
                if (i == 23 && c == 0)
                {
                    if (randomized_Value < 0.5)
                    {
                        PARAMETEREDITOR::write_Data(0x49f9c846, (2.0 / randomized_Value), 0x244, 0xFF, 0xFF); //ThardusRollSpeed
                    }
                    else if (randomized_Value < 1.0)
                    {
                        PARAMETEREDITOR::write_Data(0x49f9c846, (1.0 / randomized_Value), 0x244, 0xFF, 0xFF); //ThardusRollSpeed
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
                        if (c == 0 && i != 0 && i != 3 && i != 9 && i != 25 && i != 41 && randoScaleSeperate == true && EnemyOffsets[i][o] != 0x53411AAD && EnemyOffsets[i][o] != 0x53411D44 && EnemyOffsets[i][o] != 0x53411821 && EnemyOffsets[i][o] != 0x49f9c846 && EnemyOffsets[i][o] != 0x406e14c9)
                        {
                            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
                        }
                        if (i == 23)
                        {
                            PARAMETEREDITOR::write_Data(0x49F9CC10, randomized_Value, ThardusRock[c][e], c, i);
                        }
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], randomized_Value, PatternedAI[c][e], c, i);
                        // BIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIG
                        // Parasite Queen
                        if (EnemyOffsets[i][o] == 0x3516cb1f)
                        {
                            if (c == 0)
                            {
                                PARAMETEREDITOR::write_Data(0x3517268A, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                            }
                            else if (c == 2 && e == 1)
                            {
                                PARAMETEREDITOR::write_Data(0x35174345, randomized_Value, 0xE, 0xFF, 0xFF);
                            }
                        }
                        //Metroids In Phendrana Drifts
                        else if (EnemyOffsets[i][o] == 0x4C530038 && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x4C52B7CB, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                        }
                        else if (EnemyOffsets[i][o] == 0x4C52FCEA && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x4C52B958, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                        }
                        else if (EnemyOffsets[i][o] == 0x4C530386 && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x4C52BAE5, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                        }
                        else if (EnemyOffsets[i][o] == 0x4D537B80 && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x4D5379D5, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                        }
                        else if (EnemyOffsets[i][o] == 0x4D54D9AD && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x4D54D81A, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                        }
                        else if (EnemyOffsets[i][o] == 0x4D55380B && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x4D5535FA, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                        }
                        else if (EnemyOffsets[i][o] == 0x4A33E15C && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x4A33C313, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                        }
                        else if (EnemyOffsets[i][o] == 0x4A33DE02 && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x4A33D08E, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                        }
                        // Ridley
                        else if (EnemyOffsets[i][o] == 0x406e14c9)
                        {
                            if (c == 0)
                            {
                                PARAMETEREDITOR::write_Data(0x406EE12D, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x406EB813, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x406ED650, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x406ED971, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x406EE712, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x406F052B, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x406EB40D, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x406EAD5C, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                            }
                            else if (c == 2 && e == 1)
                            {
                                PARAMETEREDITOR::write_Data(0x406EBE9D, randomized_Value, 0xE, 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x406EBEDF, randomized_Value, 0xE, 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x406EBF21, randomized_Value, 0xE, 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x406EBF66, randomized_Value, 0xE, 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x406ED369, randomized_Value, 0xE, 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x406F0289, randomized_Value, 0xE, 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x406F497B, randomized_Value, 0xE, 0xFF, 0xFF);
                            }
                        }
                        // Elite Pirates
                        else if (EnemyOffsets[i][o] == 0x3BBDF960 && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x3BBDF0CD, ElitePirateRando, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                        }
                        else if (EnemyOffsets[i][o] == 0x3B03B855 && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x3B03B62E, ElitePirateRando, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                            PARAMETEREDITOR::write_Data(0x3B03BD4D, ElitePirateRando, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                            if (c == 2 && e == 1)
                            {
                                PARAMETEREDITOR::write_Data(0x3B03BEF7, randomized_Value, 0xE, 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x3B03BF4D, randomized_Value, 0xE, 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x3B03C000, randomized_Value, 0xE, 0xFF, 0xFF);
                            }
                        }
                        else if (EnemyOffsets[i][o] == 0x3A58DE9A && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x3A59C6C0, ElitePirateRando, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                            PARAMETEREDITOR::write_Data(0x3A58E1D3, ElitePirateRando, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                        }
                        else if (EnemyOffsets[i][o] == 0x3B8A7136 && c == 2 && e == 1)
                        {
                            PARAMETEREDITOR::write_Data(0x3BBDDC7C, randomized_Value, 0xE, 0xFF, 0xFF);
                        }
                        // Omega Pirate
                        else if (EnemyOffsets[i][o] == 0x3c40a252)
                        {
                            if (c == 0)
                            {
                                PARAMETEREDITOR::write_Data(0x3C408897, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF); //platform
                                PARAMETEREDITOR::write_Data(0x3C408BD8, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x3C407BCE, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                            }
                            else if (c == 2 && e == 1)
                            {
                                PARAMETEREDITOR::write_Data(0x3C407D77, randomized_Value, 0xE, 0xFF, 0xFF);
                            }
                        }
                        // Metroids in Phazon Mines
                        else if (EnemyOffsets[i][o] == 0x3D5FA7DE && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x3D5FB089, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                        }
                        else if (EnemyOffsets[i][o] == 0x3D5FA484 && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x3D5FB20C, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                        }
                        else if (EnemyOffsets[i][o] == 0x3D08383C && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x3D083FFA, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                        }
                        else if (EnemyOffsets[i][o] == 0x3D083B72 && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x3D08417D, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                        }

                        // Metroid Prime Essense
                        else if (EnemyOffsets[i][o] == 0x3870f0ca)
                        {
                            if (c == 0)
                            {
                                PARAMETEREDITOR::write_Data(0x3870FE95, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x38710FAE, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x38711E69, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x38712156, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x38712656, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x38712EAF, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x387133CC, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x3871479E, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x387149F2, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x38714B77, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x38714E4A, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x38715FC0, randomized_Value, 0x18 + ((e - 1) * 4), 0xFF, 0xFF);
                            }
                            else if (c == 2 && e == 1)
                            {
                                PARAMETEREDITOR::write_Data(0x38714739, randomized_Value, 0xE, 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x3871009B, randomized_Value, 0xE, 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x38711264, randomized_Value, 0xE, 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x387123C9, randomized_Value, 0xE, 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x38712415, randomized_Value, 0xE, 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x38712526, randomized_Value, 0xE, 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x38713595, randomized_Value, 0xE, 0xFF, 0xFF);
                                PARAMETEREDITOR::write_Data(0x38713604, randomized_Value, 0xE, 0xFF, 0xFF);
                            }
                        }
                        // END BIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIG
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
                    enemy_Data_Size = IncineratorDrone[c][0];
                    for (unsigned int e = 1; e < enemy_Data_Size; e++)
                    {
                        if (c == 0 && randoScaleSeperate == true)
                        {
                            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
                        }
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], randomized_Value, IncineratorDrone[c][e], c, i);
                        if (c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x54FFB591, randomized_Value, IncineratorDrone[c][e], c, i);
                        }
                        if (c == 0 && e == 3)
                        {
                            randomized_Value = PARAMETEREDITOR::randomFloat(speedLow, speedHigh);
                            PARAMETEREDITOR::write_Data(0x54FFB99F, randomized_Value, 0xE, c, 0xFF);
                            PARAMETEREDITOR::write_Data(0x54FFB9E6, randomized_Value, 0xE, c, 0xFF);
                            PARAMETEREDITOR::write_Data(0x54FFBAE7, randomized_Value, 0xE, c, 0xFF);
                            PARAMETEREDITOR::write_Data(0x54FFBB41, randomized_Value, 0xE, c, 0xFF);
                            PARAMETEREDITOR::write_Data(0x54FFBDAB, randomized_Value, 0xE, c, 0xFF);
                            PARAMETEREDITOR::write_Data(0x54FFBE30, randomized_Value, 0xE, c, 0xFF);
                            PARAMETEREDITOR::write_Data(0x54FFBECC, randomized_Value, 0xE, c, 0xFF);
                            PARAMETEREDITOR::write_Data(0x54FFBF15, randomized_Value, 0xE, c, 0xFF);
                            PARAMETEREDITOR::write_Data(0x54FFC770, randomized_Value, 0xE, c, 0xFF);
                            PARAMETEREDITOR::write_Data(0x54FFC914, randomized_Value, 0xE, c, 0xFF);
                            PARAMETEREDITOR::write_Data(0x54FFCE4A, randomized_Value, 0xE, c, 0xFF);
                            PARAMETEREDITOR::write_Data(0x54FFCEA3, randomized_Value, 0xE, c, 0xFF);
                            PARAMETEREDITOR::write_Data(0x54FFCEFD, randomized_Value, 0xE, c, 0xFF);
                            PARAMETEREDITOR::write_Data(0x54FFCF56, randomized_Value, 0xE, c, 0xFF);
                            PARAMETEREDITOR::write_Data(0x54FFCFB0, randomized_Value, 0xE, c, 0xFF);
                            PARAMETEREDITOR::write_Data(0x54FFD009, randomized_Value, 0xE, c, 0xFF);
                            PARAMETEREDITOR::write_Data(0x54FFE2A3, randomized_Value, 0xE, c, 0xFF);
                        }
                    }
                }
                else if (i == 41)
                {
                    enemy_Data_Size = MetroidPrimeStage1[c][0];
                    for (unsigned int e = 1; e < enemy_Data_Size; e++)
                    {
                        if (c == 0 && randoScaleSeperate == true)
                        {
                            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
                        }

                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], randomized_Value, MetroidPrimeStage1[c][e], c, i);
                    }
                }
                /* Save the following for chaos mode
                else if (i == 42)
                {
                    enemy_Data_Size = Platform[c][0];
                    for (unsigned int e = 1; e < enemy_Data_Size; e++)
                    {
                        randomized_Value = PARAMETEREDITOR::randomFloat(0.0, 360.0);
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], randomized_Value, 0xC, c, i);
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], randomized_Value, 0x10, c, i);
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], randomized_Value, 0x14, c, i);
                    }
                }
                else if (i == 43 && c == 0)
                {
                    enemy_Data_Size = ColorModulater_offsets[0];
                    for (unsigned int e = 1; e < enemy_Data_Size; e++)
                    {
                        randomized_Value = PARAMETEREDITOR::randomFloat(0.0, 1.0);
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], randomized_Value, 0x0, c, i);
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], randomized_Value, 0x4, c, i);
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], randomized_Value, 0x8, c, i);
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], randomized_Value, 0xC, c, i);
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], randomized_Value, 0x10, c, i);
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], randomized_Value, 0x14, c, i);
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], randomized_Value, 0x18, c, i);
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], randomized_Value, 0x1C, c, i);
                    }
                */
            }
        }
    }
    // Player Actor Fun

    /*int playerActor_Data_Size = PlayerActor_offsets[0];
    for (unsigned int e = 1; e < playerActor_Data_Size; e++)
    {
        randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        for (int i = 0; i < 3; i++)
        {
            PARAMETEREDITOR::write_Data(PlayerActor_offsets[e], randomized_Value, 0x18 + (i * 4), 0x0, 0xFF);
            if (randoScaleSeperate == true)
            {
                randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
            }
        }
    }
    playerActor_Data_Size = PlayerActorKeyFrames_offsets[0];
    for (unsigned int e = 1; e < playerActor_Data_Size; e++)
    {
        randomized_Value = PARAMETEREDITOR::randomFloat(speedLow, speedHigh);
        PARAMETEREDITOR::write_Data(PlayerActorKeyFrames_offsets[e], randomized_Value, 0xE, 0x2, 0xFF);
    }
    // Extra Actors to randomize Scale
    // Parasite Queens in tube
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x342BE8D5, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor 
        PARAMETEREDITOR::write_Data(0x342C1678, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(speedLow, speedHigh);
    PARAMETEREDITOR::write_Data(0x342BE89D, randomized_Value, 0xE, 0xFF, 0xFF); //ActorKeyFrame
    PARAMETEREDITOR::write_Data(0x342C1855, randomized_Value, 0xE, 0xFF, 0xFF); //ActorKeyFrame
    PARAMETEREDITOR::write_Data(0x342C1FCB, randomized_Value, 0xE, 0xFF, 0xFF); //ActorKeyFrame

    */
    //Samples in Biohazard Containment

    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x34AEDFC2, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor 
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x34AEE149, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x34AEE2D0, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor 
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x34AEE45A, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x34AEE5E5, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor 
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x34AEE770, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x34AEE8F9, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor 
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x34AEEA84, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x34AEEC0F, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor 
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x34AEED99, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x34AEEF8F, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor 
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x34AEF119, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x34AEFB9C, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor 
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    //Space Frigate Ridley Break Free
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x335FA6A9, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(speedLow, speedHigh);
    PARAMETEREDITOR::write_Data(0x335FC1BF, randomized_Value, 0xE, 0xFF, 0xFF); //ActorKeyFrame
    //Ridely Flyby in Phendrana Drifts
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x46C465C1, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    PARAMETEREDITOR::write_Data(0x46C4657D, randomized_Value, 0xE, 0xFF, 0xFF); //ActorKeyFrame
    PARAMETEREDITOR::write_Data(0x46C46477, randomized_Value, 0xD, 0xFF, 0xFF); //Shadow Projector
    //Drone in Research Entrance
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x496275BE, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor
        PARAMETEREDITOR::write_Data(0x49627E85, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    //Chozo Ghosts in Artifact Temple
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x406F0C35, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x406F0DB6, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x406F0F37, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x406F10B8, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x406F1239, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x406F13BA, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x406F153B, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x406F16BC, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x406F183E, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x406F19C0, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x406F1B42, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x406F1CC3, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    //Elite Pirates With No Real Pirate
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x3B899F5D, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x3B89A0DE, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x3B8A45BC, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }

    // Metroid Prime Exo Intro
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x37D37E92, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor
        PARAMETEREDITOR::write_Data(0x37D3ADE4, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor
        PARAMETEREDITOR::write_Data(0x37D3A0B0, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor
        PARAMETEREDITOR::write_Data(0x37D3AC4F, randomized_Value, 0x18 + (i * 4), 0xFF, 0xFF); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(speedLow, speedHigh);
    PARAMETEREDITOR::write_Data(0x37D39E58, randomized_Value, 0xE, 0xFF, 0xFF); //ActorKeyFrame
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
        int times = 0;
        // Drone
        while (ID == 4 && conditional == 0 && (randomized_Value > 6 || randomized_Value < 0.05))
        {
            if (times >= 50)
            {
                randomized_Value = 6;
                break;
            }
            if ((scaleLow < 0.05 && scaleHigh < 0.05) || (scaleLow > 6 && scaleHigh > 6))
            {
                if (scaleHigh > 6)
                {
                    randomized_Value = 6;
                }
                else if (scaleLow < 0.05)
                {
                    randomized_Value = 0.05;
                }
                break;
            }
            times++;
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
        times = 0;
        // ElitePirate
        while (ID == 5 && conditional == 0 && (randomized_Value > 2.3 || randomized_Value < 0.05) && (current_Offset != 0x3bbdf960 || current_Offset != 0x3b03b855 || current_Offset != 0x3a58de9a))
        {
            if (times >= 50)
            {
                randomized_Value = 2.3;
                break;
            }
            if ((scaleLow < 0.05 && scaleHigh < 0.05) || (scaleLow > 2.3 && scaleHigh > 2.3))
            {
                if (scaleHigh > 2.3)
                {
                    randomized_Value = 2.3;
                }
                else if (scaleLow < 0.05)
                {
                    randomized_Value = 0.05;
                }
                break;
            }
            times++;
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
        times = 0;
        while (ID == 5 && conditional == 0 && (randomized_Value > 1.3 || randomized_Value < 0.05) && (current_Offset == 0x3bbdf960 || current_Offset == 0x3b03b855))
        {
            if (times >= 50)
            {
                randomized_Value = 1.3;
                break;
            }
            if ((scaleLow < 0.05 && scaleHigh < 0.05) || (scaleLow > 1.3 && scaleHigh > 1.3))
            {
                if (scaleHigh > 1.3)
                {
                    randomized_Value = 1.3;
                }
                else if (scaleLow < 0.05)
                {
                    randomized_Value = 0.05;
                }
                break;
            }
            times++;
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
        times = 0;
        while (ID == 5 && conditional == 0 && (randomized_Value > 2 || randomized_Value < 0.1) && current_Offset == 0x3a58de9a)
        {
            if (times >= 50)
            {
                randomized_Value = 2;
                break;
            }
            if ((scaleLow < 0.1 && scaleHigh < 0.1) || (scaleLow > 2 && scaleHigh > 2))
            {
                if (scaleHigh > 2)
                {
                    randomized_Value = 2;
                }
                else if (scaleLow < 0.1)
                {
                    randomized_Value = 0.1;
                }
                break;
            }
            times++;
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
        times = 0;
        // IceSheegoth
        while (ID == 9 && conditional == 0 && (randomized_Value > 1.5 || randomized_Value < 0.1))
        {
            if (times >= 50)
            {
                randomized_Value = 1.5;
                break;
            }
            if ((scaleLow < 0.1 && scaleHigh < 0.1) || (scaleLow > 1.5 && scaleHigh > 1.5))
            {
                if (scaleHigh > 1.5)
                {
                    randomized_Value = 1.5;
                }
                else if (scaleLow < 0.1)
                {
                    randomized_Value = 0.1;
                }
                break;
            }
            times++;
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
        times = 0;
        // Flaahgra
        while (ID == 22 && conditional == 0 && (randomized_Value > 3.3 || randomized_Value < 0.15))
        {
            if (times >= 50)
            {
                randomized_Value = 3.3;
                break;
            }
            if ((scaleLow < 0.15 && scaleHigh < 0.15) || (scaleLow > 3.3 && scaleHigh > 3.3))
            {
                if (scaleHigh > 3.3)
                {
                    randomized_Value = 3.3;
                }
                else if (scaleLow < 0.15)
                {
                    randomized_Value = 0.15;
                }
                break;
            }
            times++;
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
        times = 0;
        // Flaahgra && Flaahgra's tentacles [speed]
        while (ID == 22 && conditional == 2 && (randomized_Value > 3 || randomized_Value < 0.05))
        {
            if (times >= 50)
            {
                randomized_Value = 3;
                break;
            }
            if ((speedLow < 0.05 && speedHigh < 0.05) || (speedLow > 2 && speedHigh > 2))
            {
                if (speedHigh > 3)
                {
                    randomized_Value = 3;
                }
                else if (speedLow < 0.05)
                {
                    randomized_Value = 0.05;
                }
                break;
            }
            times++;
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
        times = 0;
        // Thardus
        while (ID == 23 && conditional == 0 && (randomized_Value > 2 || randomized_Value < 0.05))
        {
            if (times >= 50)
            {
                randomized_Value = 2;
                break;
            }
            if ((scaleLow < 0.05 && scaleHigh < 0.05) || (scaleLow > 2 && scaleHigh > 2))
            {
                if (scaleHigh > 2)
                {
                    randomized_Value = 2;
                }
                else if (scaleLow < 0.05)
                {
                    randomized_Value = 0.05;
                }
                break;
            }
            times++;
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
        times = 0;
        // OmegaPirate
        while (ID == 24 && conditional == 0 && (randomized_Value > 2 || randomized_Value < 0.05))
        {
            if (times >= 50)
            {
                randomized_Value = 2;
                break;
            }
            if ((scaleLow < 0.05 && scaleHigh < 0.05) || (scaleLow > 2 && scaleHigh > 2))
            {
                if (scaleHigh > 2)
                {
                    randomized_Value = 2;
                }
                else if (scaleLow < 0.05)
                {
                    randomized_Value = 0.05;
                }
                break;
            }
            times++;
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
        times = 0;
        while (ID == 24 && conditional == 2 && (randomized_Value > 1.5 || randomized_Value < 0.05))
        {
            if (times >= 50)
            {
                randomized_Value = 1.5;
                break;
            }
            if ((speedLow < 0.05 && speedHigh < 0.05) || (speedLow > 1.5 && speedHigh > 1.5))
            {
                if (speedHigh > 1.5)
                {
                    randomized_Value = 1.5;
                }
                else if (speedLow < 0.05)
                {
                    randomized_Value = 0.05;
                }
                break;
            }
            times++;
            randomized_Value = PARAMETEREDITOR::randomFloat(speedLow, speedHigh);
        }
        times = 0;
        // MetaRidley
        while (ID == 25 && conditional == 0 && (randomized_Value > 1.3 || randomized_Value < 0.2))
        {
            if (times >= 50)
            {
                randomized_Value = 1.3;
                break;
            }
            if ((scaleLow < 0.2 && scaleHigh < 0.2) || (scaleLow > 1.3 && scaleHigh > 1.3))
            {
                if (scaleHigh > 1.3)
                {
                    randomized_Value = 1.3;
                }
                else if (scaleLow < 0.2)
                {
                    randomized_Value = 0.2;
                }
                break;
            }
            times++;
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
        times = 0;
        // MetroidPrimeEssense
        while (ID == 26 && conditional == 0 && (randomized_Value > 1.8 || randomized_Value < 0.05))
        {
            if (times >= 50)
            {
                randomized_Value = 1.8;
                break;
            }
            if ((scaleLow < 0.05 && scaleHigh < 0.05) || (scaleLow > 1.8 && scaleHigh > 1.8))
            {
                if (scaleHigh > 1.8)
                {
                    randomized_Value = 1.8;
                }
                else if (scaleLow < 0.05)
                {
                    randomized_Value = 0.05;
                }
                break;
            }
            times++;
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
        times = 0;
        // MetroidPrimeExo
        while (ID == 41 && conditional == 0 && (randomized_Value > 1.8 || randomized_Value < 0.15))
        {
            if (times >= 50)
            {
                randomized_Value = 1.8;
                break;
            }
            if ((scaleLow < 0.15 && scaleHigh < 0.15) || (scaleLow > 1.8 && scaleHigh > 1.8))
            {
                if (scaleHigh > 1.8)
                {
                    randomized_Value = 1.8;
                }
                else if (scaleLow < 0.15)
                {
                    randomized_Value = 0.15;
                }
                break;
            }
            times++;
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
        times = 0;
        // ParasiteQueen
        while (ID == 35 && conditional == 0 && (randomized_Value > 3 || randomized_Value < 0.1))
        {
            if (times >= 50)
            {
                randomized_Value = 3;
                break;
            }
            if ((scaleLow < 0.1 && scaleHigh < 0.1) || (scaleLow > 3 && scaleHigh > 3))
            {
                if (scaleHigh > 3)
                {
                    randomized_Value = 3;
                }
                else if (scaleLow < 0.1)
                {
                    randomized_Value = 0.1;
                }
                break;
            }
            times++;
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
        times = 0;
        // FlaahgraTentacle
        while (ID == 36 && conditional == 0 && (randomized_Value > 3 || randomized_Value < 0.05))
        {
            if (times >= 50)
            {
                randomized_Value = 3;
                break;
            }
            if ((scaleLow < 0.05 && scaleHigh < 0.05) || (scaleLow > 3 && scaleHigh > 3))
            {
                if (scaleHigh > 3)
                {
                    randomized_Value = 3;
                }
                else if (scaleLow < 0.05)
                {
                    randomized_Value = 0.05;
                }
                break;
            }
            times++;
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
        times = 0;
        // IncineratorDrone
        while (ID == 41 && conditional == 0 && (randomized_Value > 3 || randomized_Value < 0.2))
        {
            if (times >= 50)
            {
                randomized_Value = 3;
                break;
            }
            if ((scaleLow < 0.2 && scaleHigh < 0.2) || (scaleLow > 3 && scaleHigh > 3))
            {
                if (scaleHigh > 3)
                {
                    randomized_Value = 3;
                }
                else if (scaleLow < 0.2)
                {
                    randomized_Value = 0.2;
                }
                break;
            }
            times++;
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
        times = 0;
        // Specific Drones get stuck on ceiling if to big
        while ((current_Offset == 0x4A5014D6 || current_Offset == 0x4A501A0E || current_Offset == 0x4cb6effa || current_Offset == 0x4cb704da) && conditional == 0 && (randomized_Value > 1.5 || randomized_Value < 0.05))
        {
            if (times >= 50)
            {
                randomized_Value = 1.5;
                break;
            }
            if ((scaleLow < 0.05 && scaleHigh < 0.05) || (scaleLow > 1.5 && scaleHigh > 1.5))
            {
                if (scaleHigh > 1.5)
                {
                    randomized_Value = 1.5;
                }
                else if (scaleLow < 0.05)
                {
                    randomized_Value = 0.05;
                }
                break;
            }
            times++;
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
        times = 0;
        // change this so that Flaahgra's yellow health is randomized
        if (ID == 22 && conditional == 1)
        {
            return;
        }
        // don't randomized scale of StoneToad or Reaper Vine
        if (ID == 16 || ID == 21)
        {
            if (conditional == 0)
            {
                return;
            }
        }
        // Don't randomized speed of Eyon and Stone Toad
        if ((ID == 6 || ID == 21 || ID == 25) && (conditional == 2 || conditional == 3))
        {
            return;
        }
        // limit annoyingness of Chozo Ghost
        while (ID == 3 && conditional == 2 && (randomized_Value > 4 || randomized_Value < 0.05))
        {
        if (times >= 50)
        {
            randomized_Value = 4;
            break;
        }
        if ((speedLow < 0.05 && speedHigh < 0.05) || (speedLow > 4 && speedHigh > 4))
        {
            if (speedHigh > 4)
            {
                randomized_Value = 4;
            }
            else if (speedLow < 0.05)
            {
                randomized_Value = 0.05;
            }
            break;
        }
        times++;
        randomized_Value = PARAMETEREDITOR::randomFloat(speedLow, speedHigh);
        }
        times = 0;
        // If Chozo ghost is to small sometimes it can't reach its "waypoint" when it spawns
        while (ID == 3 && conditional == 0 && randomized_Value < 0.5)
        {
            if (times >= 50)
            {
                randomized_Value = 0.5;
                break;
            }
            if (scaleLow > 0.5 || (scaleLow < 0.5 && scaleHigh < 0.5))
            {
                randomized_Value = (0.5);
                break;
            }
            times++;
            randomized_Value = PARAMETEREDITOR::randomFloat(speedLow, speedHigh);
        }
        if (ID == 5)
        {
            ElitePirateRando = randomized_Value;
        }

        unsigned int value = PARAMETEREDITOR::return_Data(current_Offset + offset, false);
        float* pp = (float*)&value;
        if (ID == 42 || ID == 43)
        {
            (*pp) = randomized_Value;
        }
        else if (conditional == 3)
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
        unsigned char* address = (unsigned char*)&value;
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

    return RNG(gen);
}