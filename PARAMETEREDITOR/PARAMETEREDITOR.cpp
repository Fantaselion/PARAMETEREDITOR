#include <iostream>
#include <Simple_PARAMETER_EDITOR.h>
#include <Simple_patternedAI_Array.h>
#include <Simple_Enemy_Offset_Locations.h>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdint>
#include <vector>
#include <random>
#include <cctype>
#include <algorithm>
using namespace std;
unsigned int INSTANCE_ID;
unsigned int SCYL_SIZE;
unsigned int TYPE;
fstream in_out;
bool problem_Skiped = false;
float randomized_Value = 0;
std::random_device rd;
std::mt19937 gen;
unsigned int pak_Locations[7] = { 0x00020504, 0x00020564, 0x00020558, 0x00020540, 0x00020534, 0x0002054C, 0x00020528 };
unsigned int temp;
unsigned int ttemp;
unsigned int tteemmpp;

int main()
{
    new PARAMETEREDITOR();
    return 0;
}

PARAMETEREDITOR::PARAMETEREDITOR()
{
    gen.seed(283052733);
    in_out.open("C:/Users/nevin/Documents/Dolphin-x64/Games/a.iso", std::ios::in | std::ios::out | std::ios::binary | std::ios::ate);
    PARAMETEREDITOR::start_Here();
}

void PARAMETEREDITOR::start_Here()
{
    for (int i = 0; i < 7; i++)
    {
        pak_Locations[i] = PARAMETEREDITOR::return_Data(pak_Locations[i], false);
    }
    for (int i = 0; i < 7; i++)
    {
        if (cur_Pak == 0)
        {
            cout << "\nGetting enemy locations in 'Space Pirate Frigate'";
        }
        else if (cur_Pak == 1)
        {
            cout << " DONE\n";
            cout << "Getting enemy locations in 'Chozo Ruins'";
        }
        else if (cur_Pak == 2)
        {
            cout << " DONE\n";
            cout << "Getting enemy locations in 'Phendrana Drifts'";
        }
        else if (cur_Pak == 3)
        {
            cout << " DONE\n";
            cout << "Getting enemy locations in 'Tallon Overworld'";
        }
        else if (cur_Pak == 4)
        {
            cout << " DONE\n";
            cout << "Getting enemy locations in 'Phazon Mines'";
        }
        else if (cur_Pak == 5)
        {
            cout << " DONE\n";
            cout << "Getting enemy locations in 'Magmoor Caverns'";
        }
        else if (cur_Pak == 6)
        {
            cout << " DONE\n";
            cout << "Getting enemy locations in 'Impact Crater'";
        }
        PARAMETEREDITOR::find_Pointer_Size(pak_Locations[i]);
        cur_Pak++;
    }
    cout << " DONE\n";
    vector_BabySheegoth_offsets.insert(vector_BabySheegoth_offsets.begin(), vector_BabySheegoth_offsets.size() + 1);
    copy(vector_BabySheegoth_offsets.begin(), vector_BabySheegoth_offsets.end(), BabySheegoth_offsets);
    vector_Beetle_offsets.insert(vector_Beetle_offsets.begin(), vector_Beetle_offsets.size() + 1);
    copy(vector_Beetle_offsets.begin(), vector_Beetle_offsets.end(), Beetle_offsets);
    vector_BloodFlower_offsets.insert(vector_BloodFlower_offsets.begin(), vector_BloodFlower_offsets.size() + 1);
    copy(vector_BloodFlower_offsets.begin(), vector_BloodFlower_offsets.end(), BloodFlower_offsets);
    vector_ChozoGhost_offsets.insert(vector_ChozoGhost_offsets.begin(), vector_ChozoGhost_offsets.size() + 1);
    copy(vector_ChozoGhost_offsets.begin(), vector_ChozoGhost_offsets.end(), ChozoGhost_offsets);
    vector_Drone_offsets.insert(vector_Drone_offsets.begin(), vector_Drone_offsets.size() + 1);
    copy(vector_Drone_offsets.begin(), vector_Drone_offsets.end(), Drone_offsets);
    vector_ElitePirate_offsets.insert(vector_ElitePirate_offsets.begin(), vector_ElitePirate_offsets.size() + 1);
    copy(vector_ElitePirate_offsets.begin(), vector_ElitePirate_offsets.end(), ElitePirate_offsets);
    vector_Eyon_offsets.insert(vector_Eyon_offsets.begin(), vector_Eyon_offsets.size() + 1);
    copy(vector_Eyon_offsets.begin(), vector_Eyon_offsets.end(), Eyon_offsets);
    vector_FlyingPirate_offsets.insert(vector_FlyingPirate_offsets.begin(), vector_FlyingPirate_offsets.size() + 1);
    copy(vector_FlyingPirate_offsets.begin(), vector_FlyingPirate_offsets.end(), FlyingPirate_offsets);
    vector_HunterMetroid_offsets.insert(vector_HunterMetroid_offsets.begin(), vector_HunterMetroid_offsets.size() + 1);
    copy(vector_HunterMetroid_offsets.begin(), vector_HunterMetroid_offsets.end(), HunterMetroid_offsets);
    vector_IceSheegoth_offsets.insert(vector_IceSheegoth_offsets.begin(), vector_IceSheegoth_offsets.size() + 1);
    copy(vector_IceSheegoth_offsets.begin(), vector_IceSheegoth_offsets.end(), IceSheegoth_offsets);
    vector_Jelzap_offsets.insert(vector_Jelzap_offsets.begin(), vector_Jelzap_offsets.size() + 1);
    copy(vector_Jelzap_offsets.begin(), vector_Jelzap_offsets.end(), Jelzap_offsets);
    vector_Magmoor_offsets.insert(vector_Magmoor_offsets.begin(), vector_Magmoor_offsets.size() + 1);
    copy(vector_Magmoor_offsets.begin(), vector_Magmoor_offsets.end(), Magmoor_offsets);
    vector_Metroid_offsets.insert(vector_Metroid_offsets.begin(), vector_Metroid_offsets.size() + 1);
    copy(vector_Metroid_offsets.begin(), vector_Metroid_offsets.end(), Metroid_offsets);
    vector_PuddleSpore_offsets.insert(vector_PuddleSpore_offsets.begin(), vector_PuddleSpore_offsets.size() + 1);
    copy(vector_PuddleSpore_offsets.begin(), vector_PuddleSpore_offsets.end(), PuddleSpore_offsets);
    vector_Puffer_offsets.insert(vector_Puffer_offsets.begin(), vector_Puffer_offsets.size() + 1);
    copy(vector_Puffer_offsets.begin(), vector_Puffer_offsets.end(), Puffer_offsets);
    vector_PulseBombu_offsets.insert(vector_PulseBombu_offsets.begin(), vector_PulseBombu_offsets.size() + 1);
    copy(vector_PulseBombu_offsets.begin(), vector_PulseBombu_offsets.end(), PulseBombu_offsets);
    vector_ReaperVine_offsets.insert(vector_ReaperVine_offsets.begin(), vector_ReaperVine_offsets.size() + 1);
    copy(vector_ReaperVine_offsets.begin(), vector_ReaperVine_offsets.end(), ReaperVine_offsets);
    vector_ScatterBombu_offsets.insert(vector_ScatterBombu_offsets.begin(), vector_ScatterBombu_offsets.size() + 1);
    copy(vector_ScatterBombu_offsets.begin(), vector_ScatterBombu_offsets.end(), ScatterBombu_offsets);
    vector_Seedling_offsets.insert(vector_Seedling_offsets.begin(), vector_Seedling_offsets.size() + 1);
    copy(vector_Seedling_offsets.begin(), vector_Seedling_offsets.end(), Seedling_offsets);
    vector_Shriekbat_offsets.insert(vector_Shriekbat_offsets.begin(), vector_Shriekbat_offsets.size() + 1);
    copy(vector_Shriekbat_offsets.begin(), vector_Shriekbat_offsets.end(), Shriekbat_offsets);
    vector_SpacePirate_offsets.insert(vector_SpacePirate_offsets.begin(), vector_SpacePirate_offsets.size() + 1);
    copy(vector_SpacePirate_offsets.begin(), vector_SpacePirate_offsets.end(), SpacePirate_offsets);
    vector_StoneToad_offsets.insert(vector_StoneToad_offsets.begin(), vector_StoneToad_offsets.size() + 1);
    copy(vector_StoneToad_offsets.begin(), vector_StoneToad_offsets.end(), StoneToad_offsets);
    vector_Flaahgra_offsets.insert(vector_Flaahgra_offsets.begin(), vector_Flaahgra_offsets.size() + 1);
    copy(vector_Flaahgra_offsets.begin(), vector_Flaahgra_offsets.end(), Flaahgra_offsets);
    vector_Thardus_offsets.insert(vector_Thardus_offsets.begin(), vector_Thardus_offsets.size() + 1);
    copy(vector_Thardus_offsets.begin(), vector_Thardus_offsets.end(), Thardus_offsets);
    vector_OmegaPirate_offsets.insert(vector_OmegaPirate_offsets.begin(), vector_OmegaPirate_offsets.size() + 1);
    copy(vector_OmegaPirate_offsets.begin(), vector_OmegaPirate_offsets.end(), OmegaPirate_offsets);
    vector_MetaRidley_offsets.insert(vector_MetaRidley_offsets.begin(), vector_MetaRidley_offsets.size() + 1);
    copy(vector_MetaRidley_offsets.begin(), vector_MetaRidley_offsets.end(), MetaRidley_offsets);
    vector_MetroidPrimeStage2_offsets.insert(vector_MetroidPrimeStage2_offsets.begin(), vector_MetroidPrimeStage2_offsets.size() + 1);
    copy(vector_MetroidPrimeStage2_offsets.begin(), vector_MetroidPrimeStage2_offsets.end(), MetroidPrimeStage2_offsets);
    vector_Flickerbat_offsets.insert(vector_Flickerbat_offsets.begin(), vector_Flickerbat_offsets.size() + 1);
    copy(vector_Flickerbat_offsets.begin(), vector_Flickerbat_offsets.end(), Flickerbat_offsets);
    vector_GroundProwlers_offsets.insert(vector_GroundProwlers_offsets.begin(), vector_GroundProwlers_offsets.size() + 1);
    copy(vector_GroundProwlers_offsets.begin(), vector_GroundProwlers_offsets.end(), GroundProwlers_offsets);
    vector_Glider_offsets.insert(vector_Glider_offsets.begin(), vector_Glider_offsets.size() + 1);
    copy(vector_Glider_offsets.begin(), vector_Glider_offsets.end(), Glider_offsets);
    vector_Burrower_offsets.insert(vector_Burrower_offsets.begin(), vector_Burrower_offsets.size() + 1);
    copy(vector_Burrower_offsets.begin(), vector_Burrower_offsets.end(), Burrower_offsets);
    vector_Oculus_offsets.insert(vector_Oculus_offsets.begin(), vector_Oculus_offsets.size() + 1);
    copy(vector_Oculus_offsets.begin(), vector_Oculus_offsets.end(), Oculus_offsets);
    vector_Plazmite_offsets.insert(vector_Plazmite_offsets.begin(), vector_Plazmite_offsets.size() + 1);
    copy(vector_Plazmite_offsets.begin(), vector_Plazmite_offsets.end(), Plazmite_offsets);
    vector_Triclops_offsets.insert(vector_Triclops_offsets.begin(), vector_Triclops_offsets.size() + 1);
    copy(vector_Triclops_offsets.begin(), vector_Triclops_offsets.end(), Triclops_offsets);
    vector_WarWasp_offsets.insert(vector_WarWasp_offsets.begin(), vector_WarWasp_offsets.size() + 1);
    copy(vector_WarWasp_offsets.begin(), vector_WarWasp_offsets.end(), WarWasp_offsets);
    vector_ParasiteQueen_offsets.insert(vector_ParasiteQueen_offsets.begin(), vector_ParasiteQueen_offsets.size() + 1);
    copy(vector_ParasiteQueen_offsets.begin(), vector_ParasiteQueen_offsets.end(), ParasiteQueen_offsets);
    vector_FlaahgraTentacle_offsets.insert(vector_FlaahgraTentacle_offsets.begin(), vector_FlaahgraTentacle_offsets.size() + 1);
    copy(vector_FlaahgraTentacle_offsets.begin(), vector_FlaahgraTentacle_offsets.end(), FlaahgraTentacle_offsets);
    vector_Turret_offsets.insert(vector_Turret_offsets.begin(), vector_Turret_offsets.size() + 1);
    copy(vector_Turret_offsets.begin(), vector_Turret_offsets.end(), Turret_offsets);
    vector_AmbientAI_offsets.insert(vector_AmbientAI_offsets.begin(), vector_AmbientAI_offsets.size() + 1);
    copy(vector_AmbientAI_offsets.begin(), vector_AmbientAI_offsets.end(), AmbientAI_offsets);
    vector_Swarm_offsets.insert(vector_Swarm_offsets.begin(), vector_Swarm_offsets.size() + 1);
    copy(vector_Swarm_offsets.begin(), vector_Swarm_offsets.end(), Swarm_offsets);
    vector_MetroidPrimeStage1_offsets.insert(vector_MetroidPrimeStage1_offsets.begin(), vector_MetroidPrimeStage1_offsets.size() + 1);
    copy(vector_MetroidPrimeStage1_offsets.begin(), vector_MetroidPrimeStage1_offsets.end(), MetroidPrimeStage1_offsets);
    IncineratorDrone_offsets[0] = 2;
    IncineratorDrone_offsets[1] = int_IncineratorDrone_offsets;
    vector_IncineratorDrone_ActorKeyFrame_offsets.insert(vector_IncineratorDrone_ActorKeyFrame_offsets.begin(), vector_IncineratorDrone_ActorKeyFrame_offsets.size() + 1);
    copy(vector_IncineratorDrone_ActorKeyFrame_offsets.begin(), vector_IncineratorDrone_ActorKeyFrame_offsets.end(), IncineratorDrone_ActorKeyFrame_offsets);
    vector_IncineratorDrone_Timer_offsets.insert(vector_IncineratorDrone_Timer_offsets.begin(), vector_IncineratorDrone_Timer_offsets.size() + 1);
    copy(vector_IncineratorDrone_Timer_offsets.begin(), vector_IncineratorDrone_Timer_offsets.end(), IncineratorDrone_Timer_offsets);
    vector_Flaahgra_Timer_offsets.insert(vector_Flaahgra_Timer_offsets.begin(), vector_Flaahgra_Timer_offsets.size() + 1);
    copy(vector_Flaahgra_Timer_offsets.begin(), vector_Flaahgra_Timer_offsets.end(), Flaahgra_Timer_offsets);
    vector_OmegaPirateArmor_offsets.insert(vector_OmegaPirateArmor_offsets.begin(), vector_OmegaPirateArmor_offsets.size() + 1);
    copy(vector_OmegaPirateArmor_offsets.begin(), vector_OmegaPirateArmor_offsets.end(), OmegaPirateArmor_offsets);
    cout << "Randomizing enemy stats";
    PARAMETEREDITOR::enemy_Param_Editor();
    cout << " DONE" << endl;
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

    //input.open(inputLocation, std::ios::in | std::ios::out | std::ios::binary | std::ios::ate);
    in_out.open(outputLocation, std::ios::in | std::ios::out | std::ios::binary | std::ios::ate);

    if (in_out.is_open())
    {
        PARAMETEREDITOR::start_Here();
    }
    else
    {
        cout << "Couldn't find output file.\n" << endl;
    }
}

uint32_t PARAMETEREDITOR::ReverseBytes(uint32_t value)
{
    return (value & 0x000000FFU) << 24 | (value & 0x0000FF00U) << 8 |
        (value & 0x00FF0000U) >> 8 | (value & 0xFF000000U) >> 24;
}

int PARAMETEREDITOR::return_Data(unsigned int hex_Data, bool small_Value)
{
    if (in_out.is_open())
    {
        char data[4];
        in_out.seekg(hex_Data);
        in_out.read(data, (ifstream::pos_type)4);
        if (small_Value)
        {
            return (unsigned char)data[0];
        }

        int* value = (int*)(&data[0]); //alternately (int*)(data+23)
        int offset = ReverseBytes(value[0]);

        return offset;
    }
    else
    {
        cout << "Unable to open file, aborting enemy stat randomizer\n";
        exit(0);
    }
}

void PARAMETEREDITOR::find_Pointer_Size(unsigned int pointer)
{
    for (unsigned int i = 0, data = 0; data != 0x54585452; i++)
    {
data = PARAMETEREDITOR::return_Data(pointer + i, false);

//TXTR in hex
if (data == 0x54585452)
{
    pointer += (i + 12);
}

    }
    unsigned int pointer_Size = PARAMETEREDITOR::return_Data(pointer, false);
    PARAMETEREDITOR::MREA_SEARCH((pointer - 12), pointer_Size);
}

void PARAMETEREDITOR::MREA_SEARCH(unsigned int current_Offset, unsigned int size)
{
    for (unsigned int i = 0, data = 0; i < size; i += 0x14)
    {
        data = PARAMETEREDITOR::return_Data(current_Offset + i, false);


        //MREA in hex
        if (data == 0x4D524541)
        {
            data = PARAMETEREDITOR::return_Data(current_Offset + i + 12, false);
            PARAMETEREDITOR::SCLY_SEARCH(data + pak_Locations[cur_Pak]);
        }
    }
}

void PARAMETEREDITOR::SCLY_SEARCH(unsigned int current_Offset)
{
    unsigned int data_sections = PARAMETEREDITOR::return_Data(current_Offset + 0x3C, false);
    unsigned int section_index = PARAMETEREDITOR::return_Data(current_Offset + 0x44, false);
    unsigned int new_Offset = 0;
    current_Offset += 0x60;
    unsigned int data_Size = PARAMETEREDITOR::return_Data(current_Offset + (section_index * 4), false);
    for (int unsigned i = 0; i < section_index; i++)
    {
        new_Offset += PARAMETEREDITOR::return_Data(current_Offset + (4 * i), false);
    }
    //cout << new_Offset << endl;
    current_Offset += new_Offset + (data_sections * 4);

    //SCLY in hex
    while (PARAMETEREDITOR::return_Data(current_Offset, false) != 0x53434C59)
    {
        current_Offset += 4;
    }
    if (current_Offset == 0x3BBE5620)
    {
        cout << "yo" << endl;
    }
    PARAMETEREDITOR::enemy_Param_Searcher(current_Offset, data_Size);
}

void PARAMETEREDITOR::enemy_Param_Searcher(unsigned int current_Offset, unsigned int size)
{
    vector <unsigned int> temp_vec1{ 0x0425004C, 0x04250060, 0x04250051, 0x04250053 };
    vector <unsigned int> temp_vec2{ 0x141A019B, 0x141A019C, 0x141A019D, 0x141A019E };
    vector <unsigned int> IncinActorKeyFramesID { 0x00300030, 0x00300032, 0x0030004A, 0x0030004B, 0x00300055,
        0x00300056, 0x0030005A, 0x0030005B, 0x00300065, 0x00300069, 0x00300071, 0x00300072,
        0x00300073, 0x00300074, 0x00300075, 0x00300076, 0x00302745 };
    vector <unsigned int> IncinTimersID { 0x0030017B, 0x00302732, 0x00300012, 0x0030006A, 0x00300007,
        0x003027D6, 0x0030005C, 0x00300079, 0x00300050, 0x00300078, 0x00302737, 0x00302744,
        0x0030005D, 0x0030004D, 0x00302743, 0x00302742, 0x00300062, 0x00300041, 0x00300014,
        0x00302744, 0x00302742 };
    unsigned saved_Offset = 0;
    unsigned int initial_Offset = current_Offset;
    current_Offset += 8;
    current_Offset += (PARAMETEREDITOR::return_Data(current_Offset, false) * 4) + 9;
    while (initial_Offset + size > current_Offset)
    {
        if (INSTANCE_ID == 0x0C0801B7 && !problem_Skiped)
        {
            problem_Skiped = true;
            break;
        }

        TYPE = PARAMETEREDITOR::return_Data(current_Offset, true);
        SCYL_SIZE = PARAMETEREDITOR::return_Data(current_Offset + 1, false);
        INSTANCE_ID = PARAMETEREDITOR::return_Data(current_Offset + 5, false);
        tteemmpp = PARAMETEREDITOR::return_Data(current_Offset, false);
        if (SCYL_SIZE != 0x00000000 && SCYL_SIZE < 0x0000FFFF && initial_Offset + size - 100 > current_Offset && tteemmpp <= 0x00000000)
        {
            temp = current_Offset + SCYL_SIZE + 6;
            ttemp = PARAMETEREDITOR::return_Data(temp, false);
            if (temp >= 0x0000FFFF)
            {
                if ((SCYL_SIZE + 6 + current_Offset + 100) < (initial_Offset + size))
                {
                    current_Offset += 5;
                    continue;
                }
            }
        }
        if (SCYL_SIZE == 0x00000000)
        {
            garbage = true;
            while (garbage == true)
            {
                if (PARAMETEREDITOR::return_Data(current_Offset, true) != 0x00)
                {
                    current_Offset += 3;
                    while (PARAMETEREDITOR::return_Data(current_Offset, true) < 0x10)
                    {
                        current_Offset++;
                    }
                    current_Offset -= 9;
                    garbage = false;

                }
                else
                {
                    current_Offset++;
                }
            }
            current_Offset += SCYL_SIZE + 5;
            INSTANCE_ID = 0;
            continue;
        }
        unsigned int value = PARAMETEREDITOR::return_Data(current_Offset, true);
        if (find(IncinActorKeyFramesID.begin(), IncinActorKeyFramesID.end(), INSTANCE_ID) != IncinActorKeyFramesID.end() && cur_Pak == 1)
        {
            PARAMETEREDITOR::enemy_Start_Of_Attributes(current_Offset, SCYL_SIZE, 90);
        }
        if (find(IncinTimersID.begin(), IncinTimersID.end(), INSTANCE_ID) != IncinTimersID.end() && cur_Pak == 1)
        {
            PARAMETEREDITOR::enemy_Start_Of_Attributes(current_Offset, SCYL_SIZE, 91);
        }
        else if (INSTANCE_ID == 0x00300004 && cur_Pak == 1)
        {
            PARAMETEREDITOR::enemy_Start_Of_Attributes(current_Offset, SCYL_SIZE, 0xFF);
        }
        else if (find(temp_vec1.begin(), temp_vec1.end(), INSTANCE_ID) != temp_vec1.end() && cur_Pak == 1)
        {
            PARAMETEREDITOR::enemy_Start_Of_Attributes(current_Offset, SCYL_SIZE, 92);
        }
        else if (find(temp_vec2.begin(), temp_vec2.end(), INSTANCE_ID) != temp_vec2.end() && cur_Pak == 1)
        {
            PARAMETEREDITOR::enemy_Start_Of_Attributes(current_Offset, SCYL_SIZE, 93);
        }
        else if (INSTANCE_ID == 0x0030000E && cur_Pak == 1)
        {
            PARAMETEREDITOR::enemy_Start_Of_Attributes(current_Offset, SCYL_SIZE, 0xFF);
        }
        for (unsigned int i = 0; i < 41; i++)
        {
            if (value == objectPatterned_ID[i])
            {
                PARAMETEREDITOR::enemy_Start_Of_Attributes(current_Offset, SCYL_SIZE, i);
                i = 99;
            }
        }
        current_Offset += SCYL_SIZE + 5;
    }
}


void PARAMETEREDITOR::enemy_Start_Of_Attributes(unsigned int current_Offset, unsigned int data_Size, unsigned int object_ID_Element)
{
    unsigned int Start_Of_Data = current_Offset + 5;
    current_Offset += 9;
    unsigned int size = PARAMETEREDITOR::return_Data(current_Offset, false);
    current_Offset += 8 + (size * 0x0C);
    if (object_ID_Element == 40)
    {
        current_Offset += 4;
    }
    while (PARAMETEREDITOR::return_Data(current_Offset, true) != 0x00)
    {
        current_Offset++;
    }
    current_Offset++;

    if (INSTANCE_ID == 0x00300004 && cur_Pak == 1)
    {
        IncineratorDrone_ActorEye_offset = current_Offset;
    }
    else if (INSTANCE_ID == 0x0030000E && cur_Pak == 1)
    {
        int_IncineratorDrone_offsets = current_Offset;
    }
    else if (INSTANCE_ID != 0x04090078 && INSTANCE_ID != 0x002900A6 && INSTANCE_ID != 0x1433007C)
    {
        PARAMETEREDITOR::add_Offsets_To_Vector(current_Offset, object_ID_Element);
    }

}

void PARAMETEREDITOR::add_Offsets_To_Vector(unsigned int current_Offset, int o)
{
    switch (o)
    {
    case 0:
        vector_BabySheegoth_offsets.push_back(current_Offset);
        break;
    case 1:
        vector_Beetle_offsets.push_back(current_Offset);
        break;
    case 2:
        vector_BloodFlower_offsets.push_back(current_Offset);
        break;
    case 3:
        vector_ChozoGhost_offsets.push_back(current_Offset);
        break;
    case 4:
        vector_Drone_offsets.push_back(current_Offset);
        break;
    case 5:
        vector_ElitePirate_offsets.push_back(current_Offset);
        break;
    case 6:
        vector_Eyon_offsets.push_back(current_Offset);
        break;
    case 7:
        vector_FlyingPirate_offsets.push_back(current_Offset);
        break;
    case 8:
        vector_HunterMetroid_offsets.push_back(current_Offset);
        break;
    case 9:
        vector_IceSheegoth_offsets.push_back(current_Offset);
        break;
    case 10:
        vector_Jelzap_offsets.push_back(current_Offset);
        break;
    case 11:
        vector_Magmoor_offsets.push_back(current_Offset);
        break;
    case 12:
        vector_Metroid_offsets.push_back(current_Offset);
        break;
    case 13:
        vector_PuddleSpore_offsets.push_back(current_Offset);
        break;
    case 14:
        vector_Puffer_offsets.push_back(current_Offset);
        break;
    case 15:
        vector_PulseBombu_offsets.push_back(current_Offset);
        break;
    case 16:
        vector_ReaperVine_offsets.push_back(current_Offset);
        break;
    case 17:
        vector_ScatterBombu_offsets.push_back(current_Offset);
        break;
    case 18:
        vector_Seedling_offsets.push_back(current_Offset);
        break;
    case 19:
        vector_Shriekbat_offsets.push_back(current_Offset);
        break;
    case 20:
        vector_SpacePirate_offsets.push_back(current_Offset);
        break;
    case 21:
        vector_StoneToad_offsets.push_back(current_Offset);
        break;
    case 22:
        vector_Flaahgra_offsets.push_back(current_Offset);
        break;
    case 23:
        vector_Thardus_offsets.push_back(current_Offset);
        break;
    case 24:
        vector_OmegaPirate_offsets.push_back(current_Offset);
        break;
    case 25:
        vector_MetaRidley_offsets.push_back(current_Offset);
        break;
    case 26:
        vector_MetroidPrimeStage2_offsets.push_back(current_Offset);
        break;
    case 27:
        vector_Flickerbat_offsets.push_back(current_Offset);
        break;
    case 28:
        vector_GroundProwlers_offsets.push_back(current_Offset);
        break;
    case 29:
        vector_Glider_offsets.push_back(current_Offset);
        break;
    case 30:
        vector_Burrower_offsets.push_back(current_Offset);
        break;
    case 31:
        vector_Oculus_offsets.push_back(current_Offset);
        break;
    case 32:
        vector_Plazmite_offsets.push_back(current_Offset);
        break;
    case 33:
        vector_Triclops_offsets.push_back(current_Offset);
        break;
    case 34:
        vector_WarWasp_offsets.push_back(current_Offset);
        break;
    case 35:
        vector_ParasiteQueen_offsets.push_back(current_Offset);
        break;
    case 36:
        vector_FlaahgraTentacle_offsets.push_back(current_Offset);
        break;
    case 37:
        vector_Turret_offsets.push_back(current_Offset);
        break;
    case 38:
        vector_AmbientAI_offsets.push_back(current_Offset);
        break;
    case 39:
        vector_Swarm_offsets.push_back(current_Offset);
        break;
    case 40:
        vector_MetroidPrimeStage1_offsets.push_back(current_Offset);
        break;
    case 90:
        vector_IncineratorDrone_ActorKeyFrame_offsets.push_back(current_Offset);
        break;
    case 91:
        vector_IncineratorDrone_Timer_offsets.push_back(current_Offset);
        break;
    case 92:
        vector_Flaahgra_Timer_offsets.push_back(current_Offset);
        break;
    case 93:
        vector_OmegaPirateArmor_offsets.push_back(current_Offset);
        break;
    default:
        cout << "Something went wrong, aborting enemy stat randomizer." << endl;
        exit(1);
    }
}


void PARAMETEREDITOR::enemy_Param_Editor()
{
    unsigned int enemy_Data_Size;

    for (unsigned int i = 0; i < 43; i++)
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
                    std::cout << "something went wrong, aborting enemy stat randomizer\n" << std::endl;
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
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], EnemyInfo[i][c][e], c, i, false, o);
                    }
                }
                if (i == 23 && c == 0)
                {
                    if (randomized_Value < 0.5)
                    {
                        float temp = randomized_Value;
                        randomized_Value = 2.0 / randomized_Value;
                        PARAMETEREDITOR::write_Data(Thardus_offsets[1], 0x244, 0xFF, 0xFF, false); //ThardusRollSpeed
                        randomized_Value = temp;
                    }
                    else if (randomized_Value < 1.0)
                    {
                        float temp = randomized_Value;
                        randomized_Value = 1.0 / randomized_Value;
                        PARAMETEREDITOR::write_Data(Thardus_offsets[1], 0x244, 0xFF, 0xFF, false); //ThardusRollSpeed
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
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], PatternedAI[c][e], c, i, false, o);
                        if (c == 3 && e == 1 && EnemyOffsets[i][o] == 0x5382bf8f)
                        {
                            float temp = randomized_Value;
                            randomized_Value *= 2;
                            for (int f = 1; f < Flaahgra_Timer_offsets[0]; f++)
                            {
                                PARAMETEREDITOR::write_Data(Flaahgra_Timer_offsets[f], 0x0, c, i, false); //0425004C
                            }
                            randomized_Value = temp;
                        }
                        // BIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIG
                        // Parasite Queen
                        //if (EnemyOffsets[i][o] == 0x3516cb1f)
                        //{
                        //    if (c == 0)
                        //    {
                        //        PARAMETEREDITOR::write_Data(0x3517268A, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //    }
                        //    else if (c == 2 && e == 1)
                        //    {
                        //        PARAMETEREDITOR::write_Data(0x35174345, 0xE, 0xFF, 0xFF, false);
                        //    }
                        //}
                        //Metroids In Phendrana Drifts
                        //else if (EnemyOffsets[i][o] == 0x4C530038 && c == 0)
                        //{
                        //    PARAMETEREDITOR::write_Data(0x4C52B7CB, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //}
                        //else if (EnemyOffsets[i][o] == 0x4C52FCEA && c == 0)
                        //{
                        //    PARAMETEREDITOR::write_Data(0x4C52B958, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //}
                        //else if (EnemyOffsets[i][o] == 0x4C530386 && c == 0)
                        //{
                        //    PARAMETEREDITOR::write_Data(0x4C52BAE5, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //}
                        //else if (EnemyOffsets[i][o] == 0x4D537B80 && c == 0)
                        //{
                        //    PARAMETEREDITOR::write_Data(0x4D5379D5, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //}
                        //else if (EnemyOffsets[i][o] == 0x4D54D9AD && c == 0)
                        //{
                        //    PARAMETEREDITOR::write_Data(0x4D54D81A, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //}
                        //else if (EnemyOffsets[i][o] == 0x4D55380B && c == 0)
                        //{
                        //    PARAMETEREDITOR::write_Data(0x4D5535FA, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //}
                        //else if (EnemyOffsets[i][o] == 0x4A33E15C && c == 0)
                        //{
                        //    PARAMETEREDITOR::write_Data(0x4A33C313, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //}
                        //else if (EnemyOffsets[i][o] == 0x4A33DE02 && c == 0)
                        //{
                        //    PARAMETEREDITOR::write_Data(0x4A33D08E, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //}
                        // Ridley
                        //else if (EnemyOffsets[i][o] == 0x406e14c9)
                        //{
                        //    if (c == 0)
                        //    {
                        //        PARAMETEREDITOR::write_Data(0x406EE12D, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x406EB813, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x406ED650, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x406ED971, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x406EE712, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x406F052B, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x406EB40D, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x406EAD5C, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //    }
                        //    else if (c == 2 && e == 1)
                        //    {
                        //        PARAMETEREDITOR::write_Data(0x406EBE9D, 0xE, 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x406EBEDF, 0xE, 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x406EBF21, 0xE, 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x406EBF66, 0xE, 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x406ED369, 0xE, 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x406F0289, 0xE, 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x406F497B, 0xE, 0xFF, 0xFF, false);
                        //    }
                        //}
                        // Elite Pirates
                        //else if (EnemyOffsets[i][o] == 0x3BBDF960 && c == 0)
                        //{
                        //    PARAMETEREDITOR::write_Data(0x3BBDF0CD, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //}
                        //else if (EnemyOffsets[i][o] == 0x3B03B855 && c == 0)
                        //{
                        //    PARAMETEREDITOR::write_Data(0x3B03B62E, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //    PARAMETEREDITOR::write_Data(0x3B03BD4D, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //    if (c == 2 && e == 1)
                        //    {
                        //        PARAMETEREDITOR::write_Data(0x3B03BEF7, 0xE, 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x3B03BF4D, 0xE, 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x3B03C000, 0xE, 0xFF, 0xFF, false);
                        //    }
                        //}
                        //else if (EnemyOffsets[i][o] == 0x3A58DE9A && c == 0)
                        //{
                        //    PARAMETEREDITOR::write_Data(0x3A59C6C0, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //    PARAMETEREDITOR::write_Data(0x3A58E1D3, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //}
                        //else if (EnemyOffsets[i][o] == 0x3B8A7136 && c == 0)
                        //{
                        //    PARAMETEREDITOR::write_Data(0x3B8A45BC, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //}
                        //else if (EnemyOffsets[i][o] == 0x3B8A7136 && c == 2 && e == 1)
                        //{
                        //    PARAMETEREDITOR::write_Data(0x3BBDDC7C, 0xE, 0xFF, 0xFF, false);
                        //}
                        // Omega Pirate
                        //else if (EnemyOffsets[i][o] == 0x3c40a252)
                        //{
                        //    if (c == 0)
                        //    {
                        //        PARAMETEREDITOR::write_Data(0x3C408897, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false); //platform
                        //        PARAMETEREDITOR::write_Data(0x3C408BD8, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x3C407BCE, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //    }
                        //    else if (c == 2 && e == 1)
                        //    {
                        //        PARAMETEREDITOR::write_Data(0x3C407D77, 0xE, 0xFF, 0xFF, false);
                        //    }
                        //}
                        // Metroids in Phazon Mines
                        //else if (EnemyOffsets[i][o] == 0x3D5FA7DE && c == 0)
                        //{
                        //    PARAMETEREDITOR::write_Data(0x3D5FB089, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //}
                        //else if (EnemyOffsets[i][o] == 0x3D5FA484 && c == 0)
                        //{
                        //    PARAMETEREDITOR::write_Data(0x3D5FB20C, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //}
                        //else if (EnemyOffsets[i][o] == 0x3D08383C && c == 0)
                        //{
                        //    PARAMETEREDITOR::write_Data(0x3D083FFA, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //}
                        //else if (EnemyOffsets[i][o] == 0x3D083B72 && c == 0)
                        //{
                        //    PARAMETEREDITOR::write_Data(0x3D08417D, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //}

                        // Metroid Prime Essense
                        //else if (EnemyOffsets[i][o] == 0x3870f0ca)
                        //{
                        //    if (c == 0)
                        //    {
                        //        PARAMETEREDITOR::write_Data(0x3870FE95, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x38710FAE, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x38711E69, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x38712156, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x38712656, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x38712EAF, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x387133CC, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x3871479E, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x387149F2, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x38714B77, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x38714E4A, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x38715FC0, 0x18 + ((e - 1) * 4), 0xFF, 0xFF, false);
                        //    }
                        //    else if (c == 2 && e == 1)
                        //    {
                        //        PARAMETEREDITOR::write_Data(0x38714739, 0xE, 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x3871009B, 0xE, 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x38711264, 0xE, 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x387123C9, 0xE, 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x38712415, 0xE, 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x38712526, 0xE, 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x38713595, 0xE, 0xFF, 0xFF, false);
                        //        PARAMETEREDITOR::write_Data(0x38713604, 0xE, 0xFF, 0xFF, false);
                        //    }
                        //}
                        // END BIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIG
                        if (EnemyOffsets[i][o] == OmegaPirate_offsets[1])
                        {
                            //if (c == 0)
                            //{
                                //switch (e)
                                //{
                                //case 1:
                                    //for (int armor = 0; armor < 4; armor++)
                                    //{
                                    //    PARAMETEREDITOR::write_Data(OmegaPirateArmorScaleOffset[armor], 0x0, c, 0xFF, false);
                                    //}
                                    //for (int omega = 0; omega < 24; omega++)
                                    //{
                                    //    PARAMETEREDITOR::write_Data(OmegaPirateArmorEffectOffset[omega], 0x0, c, 0xFF, false);
                                    //}
                                    //break;
                                //case 2:
                                    //for (int armor = 0; armor < 4; armor++)
                                    //{
                                    //    PARAMETEREDITOR::write_Data(OmegaPirateArmorScaleOffset[armor], 0x4, c, 0xFF, false);
                                    //}
                                    //for (int omega = 0; omega < 24; omega++)
                                    //{
                                    //    PARAMETEREDITOR::write_Data(OmegaPirateArmorEffectOffset[omega], 0x4, c, 0xFF, false);
                                    //}
                                    //break;
                                //case 3:
                                    //for (int armor = 0; armor < 4; armor++)
                                    //{
                                    //    PARAMETEREDITOR::write_Data(OmegaPirateArmorScaleOffset[armor], 0x8, c, 0xFF, false);
                                    //}
                                    //for (int omega = 0; omega < 24; omega++)
                                    //{
                                    //    PARAMETEREDITOR::write_Data(OmegaPirateArmorEffectOffset[omega], 0x8, c, 0xFF, false);
                                    //}
                                    //break;
                                //default:
                                //    std::cout << "something went wrong, aborting enemy stat randomizer\n" << std::endl;
                                //    exit(1);
                                //}
                            //}
                            if (c == 0)
                            {
                                for (int armor = 1; armor < OmegaPirateArmor_offsets[0]; armor++)
                                PARAMETEREDITOR::write_Data(OmegaPirateArmor_offsets[armor], 0x18 + ((e - 1) * 4), c, 0xFF, false);
                            }
                            else if (c == 1 && e == 1)
                            {
                                for (int armor = 1; armor < OmegaPirateArmor_offsets[0]; armor++)
                                    PARAMETEREDITOR::write_Data(OmegaPirateArmor_offsets[armor], 0xD6, c, 0xFF, false);
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
                    enemy_Data_Size = MetroidPrimeStage1[c][0];
                    for (unsigned int e = 1; e < enemy_Data_Size; e++)
                    {
                        PARAMETEREDITOR::write_Data(EnemyOffsets[i][o], MetroidPrimeStage1[c][e], c, i, false);
                    }
                }
                else if (i == 41)
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
                        PARAMETEREDITOR::write_Data(IncineratorDrone_ActorEye_offset, IncineratorDrone[c][e], c, i, false); // Actor Contraption Eye
                    }
                    if (c == 0 && e == 3)
                    {
                        randomized_Value = PARAMETEREDITOR::randomFloat(speedLow, speedHigh);
                        //ActorKeyFrames
                        for (int a = 1; a < IncineratorDrone_ActorKeyFrame_offsets[0]; a++)
                        {
                            PARAMETEREDITOR::write_Data(IncineratorDrone_ActorKeyFrame_offsets[a], 0xE, c, 0xFF, false); // 0x00300030
                        }
                        for (int a = 1; a < IncineratorDrone_Timer_offsets[0]; a++)
                        {
                            PARAMETEREDITOR::write_Data(IncineratorDrone_Timer_offsets[a], 0x0, 3, 0xFF, false);
                            PARAMETEREDITOR::write_Data(IncineratorDrone_Timer_offsets[a], 0x4, 3, 0xFF, false);
                        }
                    }
                }
                }
            }
        }
    }
    // Extra Actors to randomize Scale
    // Parasite Queens in tube
    /*randomized_Value = PARAMETEREDITOR::randomFloat(scaleLow, scaleHigh);
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
    */
}

void PARAMETEREDITOR::write_Data(unsigned int current_Offset, unsigned int offset, unsigned int conditional, int ID, bool small_Value, unsigned int offset_Position)
{
    //if (offset_Position != 0xFFFF)
    //{
    //    cout << ID << " = " << offset_Position << endl;
    //}
    if (current_Offset < 0x00001000)
    {
        cout << "whoops, better add 1 to the iteration" << endl;
        return;
    }
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
        times = 0;
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
        while (ID == 5 && conditional == 0 && (randomized_Value > 2.3 || randomized_Value < 0.05) && offset_Position == 7)
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
        while (ID == 5 && conditional == 0 && (randomized_Value > 1.3 || randomized_Value < 0.05) && (offset_Position == 4 || offset_Position == 5))
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
        while (ID == 5 && conditional == 0 && (randomized_Value > 2 || randomized_Value < 0.1) && offset_Position == 4)
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
        while (ID == 40 && conditional == 0 && (randomized_Value > 1.8 || randomized_Value < 0.15))
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
        while ((offset_Position == 5 || offset_Position == 6 || offset_Position == 7 || offset_Position == 8) && conditional == 0 && (randomized_Value > 1.75 || randomized_Value < 0.05))
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
        vector <int> temp_vec {143, 144, 145, 146, 147, 148, 149, 150};
        while (ID == 20 && conditional == 2 && randomized_Value > 2 && find(temp_vec.begin(), temp_vec.end(), INSTANCE_ID) != temp_vec.end())
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
        if (in_out.is_open())
        {
            in_out.seekp(current_Offset + offset);
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
        if (in_out.is_open())
        {
            in_out.write((char*)&value, 4);
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
        if (in_out.is_open())
        {
            in_out.seekp(current_Offset + offset);
            in_out.write((char*)&value, 1);
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