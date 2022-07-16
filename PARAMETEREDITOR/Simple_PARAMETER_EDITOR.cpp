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

float randomized_Value = 0;
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
    scaleLow = 0.1;
    scaleHigh = 5;
    healthLow = 0.1;
    healthHigh = 5;
    speedLow = 0.01;
    speedHigh = 3;
    damageLow = 0.01;
    damageHigh = 25;
    knockbackPowerLow = 90;
    knockbackPowerHigh = 900;
    randoScaleSeperate = false;
    inputLocation = "C:/Users/Christopher/Downloads/UWU_2-0_UWU.iso";
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

    if (scaleLow > scaleHigh)
    {
        float original_scaleLow = scaleLow;
        scaleLow = scaleHigh;
        scaleHigh = original_scaleLow;
    }
    if (healthLow > healthHigh)
    {
        float original_healthLow = healthLow;
        healthLow = healthHigh;
        healthHigh = original_healthLow;
    }
    if (speedLow > speedHigh)
    {
        float original_speedLow = speedLow;
        speedLow = speedHigh;
        speedHigh = original_speedLow;
    }
    if (damageLow > damageHigh)
    {
        float original_damageLow = damageLow;
        damageLow = damageHigh;
        damageHigh = original_damageLow;
    }
    if (knockbackPowerLow > knockbackPowerHigh)
    {
        float original_knockbackPowerLow = knockbackPowerLow;
        knockbackPowerLow = knockbackPowerHigh;
        knockbackPowerHigh = original_knockbackPowerLow;
    }

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
    unsigned int enemy_Data_Size;

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
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], EnemyInfo[i][c][e], c, i, false);
                    }
                }
                if (i == 23 && c == 0)
                {
                    if (randomized_Value < 0.5)
                    {
                        float temp = randomized_Value;
                        randomized_Value = 2.0 / randomized_Value;
                        PARAMETEREDITOR::write_Data(0x49f9c846, 0x244, 0xFF, 0xFF, false); //ThardusRollSpeed
                        randomized_Value = temp;
                    }
                    else if (randomized_Value < 1.0)
                    {
                        float temp = randomized_Value;
                        randomized_Value = 1.0 / randomized_Value;
                        PARAMETEREDITOR::write_Data(0x49f9c846, 0x244, 0xFF, 0xFF, false); //ThardusRollSpeed
                        randomized_Value = temp;
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
                        if (c == 0 && i != 0 && i != 3 && i != 9 && i != 23 && i != 25 && randoScaleSeperate == true && EnemyOffsets[i][o] != 0x53411AAD && EnemyOffsets[i][o] != 0x53411D44 && EnemyOffsets[i][o] != 0x53411821 && EnemyOffsets[i][o] != 0x49f9c846 && EnemyOffsets[i][o] != 0x406e14c9)
                        {
                            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
                        }
                        if (i == 23)
                        {
                            PARAMETEREDITOR::write_Data(0x49F9CC10, ThardusRock[c][e], c, i, false);
                        }
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], PatternedAI[c][e], c, i, false);
                        if (c == 3 && e == 1 && EnemyOffsets[i][o] == 0x5382bf8f)
                        {
                            float temp = randomized_Value;
                            randomized_Value *= 2;
                            PARAMETEREDITOR::write_Data(0x5382D7FE, 0x0, c, i, false);
                            PARAMETEREDITOR::write_Data(0x5382E248, 0x0, c, i, false);
                            PARAMETEREDITOR::write_Data(0x5382E4D4, 0x0, c, i, false);
                            PARAMETEREDITOR::write_Data(0x5382E52A, 0x0, c, i, false);
                            randomized_Value = temp;
                        }
                        // BIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIG
                        // Parasite Queen
                        if (EnemyOffsets[i][o] == 0x3516cb1f)
                        {
                            if (c == 0)
                            {
                                PARAMETEREDITOR::write_Data(0x3517268A, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                            }
                            else if (c == 2 && e == 1)
                            {
                                PARAMETEREDITOR::write_Data(0x35174345, 0xE, 0xFF, 0xFF, false);
                            }
                        }
                        //Metroids In Phendrana Drifts
                        else if (EnemyOffsets[i][o] == 0x4C530038 && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x4C52B7CB, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        }
                        else if (EnemyOffsets[i][o] == 0x4C52FCEA && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x4C52B958, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        }
                        else if (EnemyOffsets[i][o] == 0x4C530386 && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x4C52BAE5, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        }
                        else if (EnemyOffsets[i][o] == 0x4D537B80 && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x4D5379D5, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        }
                        else if (EnemyOffsets[i][o] == 0x4D54D9AD && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x4D54D81A, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        }
                        else if (EnemyOffsets[i][o] == 0x4D55380B && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x4D5535FA, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        }
                        else if (EnemyOffsets[i][o] == 0x4A33E15C && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x4A33C313, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        }
                        else if (EnemyOffsets[i][o] == 0x4A33DE02 && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x4A33D08E, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        }
                        // Ridley
                        else if (EnemyOffsets[i][o] == 0x406e14c9)
                        {
                            if (c == 0)
                            {
                                PARAMETEREDITOR::write_Data(0x406EE12D, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x406EB813, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x406ED650, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x406ED971, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x406EE712, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x406F052B, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x406EB40D, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x406EAD5C, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                            }
                            else if (c == 2 && e == 1)
                            {
                                PARAMETEREDITOR::write_Data(0x406EBE9D, 0xE, 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x406EBEDF, 0xE, 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x406EBF21, 0xE, 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x406EBF66, 0xE, 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x406ED369, 0xE, 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x406F0289, 0xE, 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x406F497B, 0xE, 0xFF, 0xFF, false);
                            }
                        }
                        // Elite Pirates
                        else if (EnemyOffsets[i][o] == 0x3BBDF960 && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x3BBDF0CD, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        }
                        else if (EnemyOffsets[i][o] == 0x3B03B855 && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x3B03B62E, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                            PARAMETEREDITOR::write_Data(0x3B03BD4D, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                            if (c == 2 && e == 1)
                            {
                                PARAMETEREDITOR::write_Data(0x3B03BEF7, 0xE, 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x3B03BF4D, 0xE, 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x3B03C000, 0xE, 0xFF, 0xFF, false);
                            }
                        }
                        else if (EnemyOffsets[i][o] == 0x3A58DE9A && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x3A59C6C0, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                            PARAMETEREDITOR::write_Data(0x3A58E1D3, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        }
                        else if (EnemyOffsets[i][o] == 0x3B8A7136 && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x3B8A45BC, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        }
                        else if (EnemyOffsets[i][o] == 0x3B8A7136 && c == 2 && e == 1)
                        {
                            PARAMETEREDITOR::write_Data(0x3BBDDC7C, 0xE, 0xFF, 0xFF, false);
                        }
                        // Omega Pirate
                        else if (EnemyOffsets[i][o] == 0x3c40a252)
                        {
                            if (c == 0)
                            {
                                PARAMETEREDITOR::write_Data(0x3C408897, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false); //platform
                                PARAMETEREDITOR::write_Data(0x3C408BD8, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x3C407BCE, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                            }
                            else if (c == 2 && e == 1)
                            {
                                PARAMETEREDITOR::write_Data(0x3C407D77, 0xE, 0xFF, 0xFF, false);
                            }
                        }
                        // Metroids in Phazon Mines
                        else if (EnemyOffsets[i][o] == 0x3D5FA7DE && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x3D5FB089, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        }
                        else if (EnemyOffsets[i][o] == 0x3D5FA484 && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x3D5FB20C, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        }
                        else if (EnemyOffsets[i][o] == 0x3D08383C && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x3D083FFA, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        }
                        else if (EnemyOffsets[i][o] == 0x3D083B72 && c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x3D08417D, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        }

                        // Metroid Prime Essense
                        else if (EnemyOffsets[i][o] == 0x3870f0ca)
                        {
                            if (c == 0)
                            {
                                PARAMETEREDITOR::write_Data(0x3870FE95, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x38710FAE, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x38711E69, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x38712156, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x38712656, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x38712EAF, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x387133CC, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x3871479E, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x387149F2, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x38714B77, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x38714E4A, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x38715FC0, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                            }
                            else if (c == 2 && e == 1)
                            {
                                PARAMETEREDITOR::write_Data(0x38714739, 0xE, 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x3871009B, 0xE, 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x38711264, 0xE, 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x387123C9, 0xE, 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x38712415, 0xE, 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x38712526, 0xE, 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x38713595, 0xE, 0xFF, 0xFF, false);
                                PARAMETEREDITOR::write_Data(0x38713604, 0xE, 0xFF, 0xFF, false);
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
                                        PARAMETEREDITOR::write_Data(OmegaPirateArmorScaleOffset[armor], 0x0, c, 0xFF, false);
                                    }
                                    for (int omega = 0; omega < 24; omega++)
                                    {
                                        PARAMETEREDITOR::write_Data(OmegaPirateArmorEffectOffset[omega], 0x0, c, 0xFF, false);
                                    }
                                    break;
                                case 2:
                                    for (int armor = 0; armor < 4; armor++)
                                    {
                                        PARAMETEREDITOR::write_Data(OmegaPirateArmorScaleOffset[armor], 0x4, c, 0xFF, false);
                                    }
                                    for (int omega = 0; omega < 24; omega++)
                                    {
                                        PARAMETEREDITOR::write_Data(OmegaPirateArmorEffectOffset[omega], 0x4, c, 0xFF, false);
                                    }
                                    break;
                                case 3:
                                    for (int armor = 0; armor < 4; armor++)
                                    {
                                        PARAMETEREDITOR::write_Data(OmegaPirateArmorScaleOffset[armor], 0x8, c, 0xFF, false);
                                    }
                                    for (int omega = 0; omega < 24; omega++)
                                    {
                                        PARAMETEREDITOR::write_Data(OmegaPirateArmorEffectOffset[omega], 0x8, c, 0xFF, false);
                                    }
                                    break;
                                default:
                                    std::cout << "something went wrong\n" << std::endl;
                                    exit(1);
                                }
                            }
                            else if (c == 1 && e == 1)
                            {
                            PARAMETEREDITOR::write_Data(0x3C40B163, 0x0, c, 0xFF, false);
                            PARAMETEREDITOR::write_Data(0x3C40B368, 0x0, c, 0xFF, false);
                            PARAMETEREDITOR::write_Data(0x3C40B568, 0x0, c, 0xFF, false);
                            PARAMETEREDITOR::write_Data(0x3C40B75C, 0x0, c, 0xFF, false);
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
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], Turret[c][e], c, i, false);
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
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], AmbientAI[c][e], c, i, false);
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
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], Swarm[c][e], c, i, false);
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
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], IncineratorDrone[c][e], c, i, false);
                        if (c == 0)
                        {
                            PARAMETEREDITOR::write_Data(0x54FFB591, IncineratorDrone[c][e], c, i, false);
                        }
                        if (c == 0 && e == 3)
                        {
                            randomized_Value = PARAMETEREDITOR::randomFloat(speedLow, speedHigh);
                            PARAMETEREDITOR::write_Data(0x54FFB99F, 0xE, c, 0xFF, false);
                            PARAMETEREDITOR::write_Data(0x54FFB9E6, 0xE, c, 0xFF, false);
                            PARAMETEREDITOR::write_Data(0x54FFBAE7, 0xE, c, 0xFF, false);
                            PARAMETEREDITOR::write_Data(0x54FFBB41, 0xE, c, 0xFF, false);
                            PARAMETEREDITOR::write_Data(0x54FFBDAB, 0xE, c, 0xFF, false);
                            PARAMETEREDITOR::write_Data(0x54FFBE30, 0xE, c, 0xFF, false);
                            PARAMETEREDITOR::write_Data(0x54FFBECC, 0xE, c, 0xFF, false);
                            PARAMETEREDITOR::write_Data(0x54FFBF15, 0xE, c, 0xFF, false);
                            PARAMETEREDITOR::write_Data(0x54FFC770, 0xE, c, 0xFF, false);
                            PARAMETEREDITOR::write_Data(0x54FFC914, 0xE, c, 0xFF, false);
                            PARAMETEREDITOR::write_Data(0x54FFCE4A, 0xE, c, 0xFF, false);
                            PARAMETEREDITOR::write_Data(0x54FFCEA3, 0xE, c, 0xFF, false);
                            PARAMETEREDITOR::write_Data(0x54FFCEFD, 0xE, c, 0xFF, false);
                            PARAMETEREDITOR::write_Data(0x54FFCF56, 0xE, c, 0xFF, false);
                            PARAMETEREDITOR::write_Data(0x54FFCFB0, 0xE, c, 0xFF, false);
                            PARAMETEREDITOR::write_Data(0x54FFD009, 0xE, c, 0xFF, false);
                            PARAMETEREDITOR::write_Data(0x54FFE2A3, 0xE, c, 0xFF, false);
                            for (int a = 0; a < 21; a++)
                            {
                                PARAMETEREDITOR::write_Data(IncineratorDroneTimers[a], 0x0, 3, 0xFF, false);
                                PARAMETEREDITOR::write_Data(IncineratorDroneTimers[a], 0x4, 3, 0xFF, false);
                            }
                        }
                    }
                }
                else if (i == 41)
                {
                    enemy_Data_Size = MetroidPrimeStage1[c][0];
                    for (unsigned int e = 1; e < enemy_Data_Size; e++)
                    {
                        //if (c == 0 && randoScaleSeperate == true)
                        //{
                        //    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
                        //}
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], MetroidPrimeStage1[c][e], c, i, false);
                    }
                }
                //randomized_Value = PARAMETEREDITOR::randomFloat(0.0, 360.0);
                //PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], 0xC, 0xDD, i, false);
                //PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], 0x10, 0xDD, i, false);
                //PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], 0x14, 0xDD, i, false);
            }
        }
    }
    // Save the following for chaos mode
    /*
    enemy_Data_Size = Platform_offsets[0];
    for (unsigned int e = 1; e < enemy_Data_Size; e++)
    {
        if (Platform_offsets[e] == 0x538315B1 || Platform_offsets[e] == 0x53832120 || Platform_offsets[e] == 0x538329F9 || 
            Platform_offsets[e] == 0x538332DE || Platform_offsets[e] == 0x33BFD5C0 || Platform_offsets[e] == 0x34534230 ||
            Platform_offsets[e] == 0x5382FC3A || Platform_offsets[e] == 0x5382FEF7 || Platform_offsets[e] == 0x538301B4 ||
            Platform_offsets[e] == 0x53830471 || Platform_offsets[e] == 0x4BDCF1B9 || Platform_offsets[e] == 0x4FF75605 ||
            Platform_offsets[e] == 0x447F6172 || Platform_offsets[e] == 0x447F669F || Platform_offsets[e] == 0x447F6BCC || 
            Platform_offsets[e] == 0x447F70F9 || Platform_offsets[e] == 0x447F7626 || Platform_offsets[e] == 0x447F7B53 ||
            Platform_offsets[e] == 0x5548AD2A || Platform_offsets[e] == 0x5548B02F || Platform_offsets[e] == 0x5548B334 || 
            Platform_offsets[e] == 0x5548B639 || Platform_offsets[e] == 0x5548B93E || Platform_offsets[e] == 0x5548BC43 || 
            Platform_offsets[e] == 0x5548BF48 || Platform_offsets[e] == 0x55CE688F || Platform_offsets[e] == 0x55CE66E3 ||
            Platform_offsets[e] == 0x475200C3 || Platform_offsets[e] == 0x4BDD000F || Platform_offsets[e] == 0x454325E5 ||
            Platform_offsets[e] == 0x45434B0D || Platform_offsets[e] == 0x4C7A2E10 || Platform_offsets[e] == 0x3C40053A ||
            Platform_offsets[e] == 0x3C40225A || Platform_offsets[e] == 0x3E8F978A)
        {
            continue;
        }
        randomized_Value = PARAMETEREDITOR::randomFloat(0.0, 360.0);
        PARAMETEREDITOR::write_Data(Platform_offsets[e], 0xC, 0xDD, 0xFF, false);
        PARAMETEREDITOR::write_Data(Platform_offsets[e], 0x10, 0xDD, 0xFF, false);
        PARAMETEREDITOR::write_Data(Platform_offsets[e], 0x14, 0xDD, 0xFF, false);
    }
    enemy_Data_Size = Actor_offsets[0];
    for (unsigned int e = 1; e < enemy_Data_Size; e++)
    {
        if (Actor_offsets[e] == 0x51F03175 || Actor_offsets[e] == 0x539591A0 || Actor_offsets[e] == 0x3A7DA947 ||
            Actor_offsets[e] == 0x50C3F1D5 || Actor_offsets[e] == 0x54FFAB66 || Actor_offsets[e] == 0x4FA0EBC0 || 
            Actor_offsets[e] == 0x54183EA4 || Actor_offsets[e] == 0x55CED047 || Actor_offsets[e] == 0x3C401D22 ||
            Actor_offsets[e] == 0x54FFB591 || Actor_offsets[e] == 0x45CE2965 || Actor_offsets[e] == 0x3DC6C9FF ||
            Actor_offsets[e] == 0x5382C5F9 || Actor_offsets[e] == 0x5382C778 || Actor_offsets[e] == 0x5382C8F6 ||
            Actor_offsets[e] == 0x5382CA75 || Actor_offsets[e] == 0x43CE41E5 || Actor_offsets[e] == 0x43CE5321 ||
            Actor_offsets[e] == 0x48144E18 || Actor_offsets[e] == 0x45CE2AF8 || Actor_offsets[e] == 0x45CE2C8B ||
            Actor_offsets[e] == 0x4F2F19A5 || Actor_offsets[e] == 0x4B32C658 || Actor_offsets[e] == 0x4CB030F9 ||
            Actor_offsets[e] == 0x523BE7D3 || Actor_offsets[e] == 0x523BFCBA || Actor_offsets[e] == 0x523C0185 ||
            Actor_offsets[e] == 0x3C91248D || Actor_offsets[e] == 0x3B6714D3 || Actor_offsets[e] == 0x3B67164C ||
            Actor_offsets[e] == 0x3B6717C5 || Actor_offsets[e] == 0x3B67193E || Actor_offsets[e] == 0x3B671AB7 ||
            Actor_offsets[e] == 0x3B671C30 || Actor_offsets[e] == 0x3B673D3B || Actor_offsets[e] == 0x55CE7216 ||
            Actor_offsets[e] == 0x55CED1E1 || Actor_offsets[e] == 0x55CED37C || Actor_offsets[e] == 0x55CED518)
        {
            continue;
        }
        randomized_Value = PARAMETEREDITOR::randomFloat(0.0, 360.0);
        PARAMETEREDITOR::write_Data(Actor_offsets[e], 0xC, 0xDD, 0xFF, false);
        PARAMETEREDITOR::write_Data(Actor_offsets[e], 0x10, 0xDD, 0xFF, false);
        PARAMETEREDITOR::write_Data(Actor_offsets[e], 0x14, 0xDD, 0xFF, false);
        PARAMETEREDITOR::write_Data(Actor_offsets[e], 0x152, 0xFF, 0x01, true);
    }
    enemy_Data_Size = ColorModulater_offsets[0];
    for (unsigned int e = 1; e < enemy_Data_Size; e++)
    {
        randomized_Value = PARAMETEREDITOR::randomFloat(0.0, 1.0);
        PARAMETEREDITOR::write_Data(ColorModulater_offsets[e], 0x0, 0xDD, 0xFF, false);
        PARAMETEREDITOR::write_Data(ColorModulater_offsets[e], 0x4, 0xDD, 0xFF, false);
        PARAMETEREDITOR::write_Data(ColorModulater_offsets[e], 0x8, 0xDD, 0xFF, false);
        //PARAMETEREDITOR::write_Data(ColorModulater_offsets[e], 0xC, 0xDD, 0xFF, false);
        PARAMETEREDITOR::write_Data(ColorModulater_offsets[e], 0x10, 0xDD, 0xFF, false);
        PARAMETEREDITOR::write_Data(ColorModulater_offsets[e], 0x14, 0xDD, 0xFF, false);
        PARAMETEREDITOR::write_Data(ColorModulater_offsets[e], 0x18, 0xDD, 0xFF, false);
        //PARAMETEREDITOR::write_Data(ColorModulater_offsets[e], 0x1C, 0xDD, 0xFF, false);
    }
    enemy_Data_Size = AreaAttribute_offsets[0];
    for (unsigned int e = 1; e < enemy_Data_Size; e++)
    {
        randomized_Value = PARAMETEREDITOR::randomFloat(0.0, 1.0);
        randomized_Value = 0.0;
        PARAMETEREDITOR::write_Data(AreaAttribute_offsets[e], 0x26, 0xDD, 0xFF, false);
    }
    
    // Player Actor Fun

    int playerActor_Data_Size = PlayerActor_offsets[0];
    for (unsigned int e = 1; e < playerActor_Data_Size; e++)
    {
        randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        for (int i = 0; i < 3; i++)
        {
            PARAMETEREDITOR::write_Data(PlayerActor_offsets[e], 0x18 + (i * 4), 0x0, 0xFF, false);
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
        PARAMETEREDITOR::write_Data(PlayerActorKeyFrames_offsets[e], 0xE, 0x2, 0xFF, false);
    }
    */
    // Extra Actors to randomize Scale
    // Parasite Queens in tube
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x342BE8D5, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor 
        PARAMETEREDITOR::write_Data(0x342C1678, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(speedLow, speedHigh);
    PARAMETEREDITOR::write_Data(0x342BE89D, 0xE, 0xFF, 0xFF, false); //ActorKeyFrame
    PARAMETEREDITOR::write_Data(0x342C1855, 0xE, 0xFF, 0xFF, false); //ActorKeyFrame
    PARAMETEREDITOR::write_Data(0x342C1FCB, 0xE, 0xFF, 0xFF, false); //ActorKeyFrame

    //Samples in Biohazard Containment

    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x34AEDFC2, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor 
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x34AEE149, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x34AEE2D0, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor 
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x34AEE45A, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x34AEE5E5, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor 
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x34AEE770, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x34AEE8F9, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor 
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x34AEEA84, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x34AEEC0F, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor 
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x34AEED99, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x34AEEF8F, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor 
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x34AEF119, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x34AEFB9C, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor 
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    //Space Frigate Ridley Break Free
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x335FA6A9, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(speedLow, speedHigh);
    PARAMETEREDITOR::write_Data(0x335FC1BF, 0xE, 0xFF, 0xFF, false); //ActorKeyFrame
    //Ridely Flyby in Phendrana Drifts
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x46C465C1, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    PARAMETEREDITOR::write_Data(0x46C4657D, 0xE, 0xFF, 0xFF, false); //ActorKeyFrame
    PARAMETEREDITOR::write_Data(0x46C46477, 0xD, 0xFF, 0xFF, false); //Shadow Projector
    //Drone in Research Entrance
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x496275BE, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor
        PARAMETEREDITOR::write_Data(0x49627E85, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    //Chozo Ghosts in Artifact Temple
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x406F0C35, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x406F0DB6, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x406F0F37, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x406F10B8, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x406F1239, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x406F13BA, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x406F153B, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x406F16BC, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x406F183E, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x406F19C0, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x406F1B42, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x406F1CC3, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    //Elite Pirates With No Real Pirate
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x3B899F5D, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x3B89A0DE, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }

    //Elite Pirate Actors to make not solid
    PARAMETEREDITOR::write_Data(0x3B899F5D, 0x153, 0xFF, 0x00, true);
    PARAMETEREDITOR::write_Data(0x3B89A0DE, 0x153, 0xFF, 0x00, true);
    PARAMETEREDITOR::write_Data(0x3B8A45BC, 0x153, 0xFF, 0x00, true);
    // Metroid Prime Exo Intro
    randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
    for (int i = 0; i < 3; i++)
    {
        PARAMETEREDITOR::write_Data(0x37D37E92, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor
        PARAMETEREDITOR::write_Data(0x37D3ADE4, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor
        PARAMETEREDITOR::write_Data(0x37D3A0B0, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor
        PARAMETEREDITOR::write_Data(0x37D3AC4F, 0x18 + (i * 4), 0xFF, 0xFF, false); //Actor
        if (randoScaleSeperate == true)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
    }
    randomized_Value = PARAMETEREDITOR::randomFloat(speedLow, speedHigh);
    PARAMETEREDITOR::write_Data(0x37D39E58, 0xE, 0xFF, 0xFF, false); //ActorKeyFrame
}

void PARAMETEREDITOR::write_Data(unsigned int current_Offset, unsigned int offset, unsigned int conditional, int ID, bool small_Value)
{
    //if (offset != 0x000)
    if (small_Value == false)
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
                randomized_Value = PARAMETEREDITOR::randomFloat(0.05, 6);
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
                randomized_Value = PARAMETEREDITOR::randomFloat(0.05, 2.3);
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
                randomized_Value = PARAMETEREDITOR::randomFloat(0.05, 1.3);
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
                randomized_Value = PARAMETEREDITOR::randomFloat(0.1, 2.0);
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
                randomized_Value = PARAMETEREDITOR::randomFloat(0.1, 1.5);
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
                randomized_Value = PARAMETEREDITOR::randomFloat(0.15, 3.3);
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
                randomized_Value = PARAMETEREDITOR::randomFloat(0.05, 3.0);
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
            randomized_Value = PARAMETEREDITOR::randomFloat(speedLow, speedHigh);
        }
        times = 0;
        // Thardus
        while (ID == 23 && conditional == 0 && (randomized_Value > 2 || randomized_Value < 0.05))
        {
            if (times >= 50)
            {
                randomized_Value = PARAMETEREDITOR::randomFloat(0.05, 2.0);
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
                randomized_Value = PARAMETEREDITOR::randomFloat(0.05, 2.0);
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
        while (ID == 24 && conditional == 2 && (randomized_Value > 1.5 || randomized_Value < 0.50))
        {
            if (times >= 50)
            {
                randomized_Value = PARAMETEREDITOR::randomFloat(0.05, 1.5);
                break;
            }
            if ((speedLow < 0.50 && speedHigh < 0.50) || (speedLow > 1.5 && speedHigh > 1.5))
            {
                if (speedHigh > 1.5)
                {
                    randomized_Value = 1.5;
                }
                else if (speedLow < 0.50)
                {
                    randomized_Value = 0.50;
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
                randomized_Value = PARAMETEREDITOR::randomFloat(0.2, 1.3);
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
                randomized_Value = PARAMETEREDITOR::randomFloat(0.05, 1.8);
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
                randomized_Value = PARAMETEREDITOR::randomFloat(0.15, 1.8);
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
                randomized_Value = PARAMETEREDITOR::randomFloat(0.1, 3.0);
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
                randomized_Value = PARAMETEREDITOR::randomFloat(0.05, 3.0);
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
                randomized_Value = PARAMETEREDITOR::randomFloat(0.2, 3.0);
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
        while ((current_Offset == 0x4A5014D6 || current_Offset == 0x4A501A0E || current_Offset == 0x4cb6effa || current_Offset == 0x4cb704da) && conditional == 0 && (randomized_Value > 1.75 || randomized_Value < 0.05))
        {
            if (times >= 50)
            {
                randomized_Value = PARAMETEREDITOR::randomFloat(0.05, 1.75);
                break;
            }
            if ((scaleLow < 0.05 && scaleHigh < 0.05) || (scaleLow > 1.75 && scaleHigh > 1.75))
            {
                if (scaleHigh > 1.75)
                {
                    randomized_Value = 1.75;
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
        while (ID == 3 && conditional == 2 && (randomized_Value > 2.5 || randomized_Value < 0.05))
        {
        if (times >= 50)
        {
            randomized_Value = PARAMETEREDITOR::randomFloat(0.05, 2.5);
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
                randomized_Value = 2;
                break;
            }
            times++;
            randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
        }
        times = 0;
        // Limit speed of space pirates in Elite Pirate room
        while (ID == 20 && conditional == 2 && randomized_Value > 2 && (current_Offset == 0x3C40E944 || current_Offset == 0x3C40EC64 ||
            current_Offset == 0x3C41072B || current_Offset == 0x3C411689 || current_Offset == 0x3C412260 || current_Offset == 0x3C412564 ||
            current_Offset == 0x3C41286B || current_Offset == 0x3C412B70))
        {
            if (times >= 50)
            {
                randomized_Value = PARAMETEREDITOR::randomFloat(0.05, 2.0);
                break;
            }
            if (speedLow > 2 || (speedLow > 2 && speedHigh > 2))
            {
                randomized_Value = 2;
                break;
            }
            times++;
            randomized_Value = PARAMETEREDITOR::randomFloat(speedLow, speedHigh);
        }

        unsigned int value = PARAMETEREDITOR::return_Data(current_Offset + offset, false);
        float* pp = (float*)&value;
        if (conditional == 0xDD)
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
    else if (ID != 21)
    {
        if (ID == 1 || ID == 4 || ID == 6 || ID == 12 || ID == 13 || ID == 21 || ID == 27 || ID == 28 || ID == 29 || ID == 34 || ID == 37)
        {
            offset += 0x4;
        }
        unsigned int value = 0;
        float* pp = (float*)&value;
        (*pp) = ID;
        if (output.is_open())
        {
            output.seekp(current_Offset + offset);
            output.write((char*)&value, 1);
        }
        else if (input.is_open())
        {
            input.seekp(current_Offset + offset);
            input.write((char*)&value, 1);
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