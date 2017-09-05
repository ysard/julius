#include "AllData.h"

#define DATA_INTERN 1
#include "Grid.h"

struct Data_Model_Difficulty Data_Model_Difficulty = {
	{300, 200, 150, 100, 75}, // money percentage
	{40, 60, 80, 100, 120}, // enemy percentage
	{70, 60, 50, 50, 40}, // starting favor
	{80, 70, 60, 50, 40}, // sentiment
};

struct _Data_Scenario Data_Scenario;

struct _Data_Event Data_Event = {0};

struct _Data_Settings Data_Settings;
struct _Data_Settings_Map Data_Settings_Map;

struct _Data_Tutorial Data_Tutorial;

struct _Data_Message Data_Message;

struct _Data_Empire Data_Empire;
struct _Data_Empire_Sizes Data_Empire_Sizes = {2000, 1000, 16, 16, 120};
struct Data_Empire_Index Data_Empire_Index[40];
struct Data_Empire_Object Data_Empire_Objects[MAX_EMPIRE_OBJECTS];
struct Data_Empire_City Data_Empire_Cities[MAX_EMPIRE_CITIES];

struct _Data_Screen Data_Screen;// = { 800, 600, {80, 60} };

struct _Data_CityInfo Data_CityInfo;
struct _Data_CityInfo_CultureCoverage Data_CityInfo_CultureCoverage;
struct _Data_CityInfo_Extra Data_CityInfo_Extra;
struct _Data_CityInfo_Resource Data_CityInfo_Resource;

struct Data_KeyboardInput Data_KeyboardInput;

struct _Data_State Data_State;

struct Data_Figure Data_Figures[MAX_FIGURES];
struct _Data_Figure_Extra Data_Figure_Extra;

struct Data_Building Data_Buildings[MAX_BUILDINGS];
struct Data_Building_Storage Data_Building_Storages[MAX_STORAGES];
struct _Data_Buildings_Extra Data_Buildings_Extra;
struct _Data_BuildingList Data_BuildingList;

struct Data_Sound_City Data_Sound_City[70];

struct Data_CityView Data_CityView;

struct Data_InvasionWarning Data_InvasionWarnings[MAX_INVASION_WARNINGS];

struct _Data_FileList Data_FileList;

struct _Data_Routes Data_Routes;

struct _Data_Debug Data_Debug;

const int Constant_SalaryForRank[11] = {0, 2, 5, 8, 12, 20, 30, 40, 60, 80, 100};
const int Constant_DirectionGridOffsets[8] = {-162, -161, 1, 163, 162, 161, -1, -163};

const struct BuildingProperties Constant_BuildingProperties[140] = {
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{1, 0, 0x70, 0},
	{1, 0, 0x18, 0x1A},
	{1, 0, 0, 0},
	{1, 0, 0x13, 2},
	{0, 0, 0, 0},
	{1, 0, 0, 0},
	{1, 0, 0, 0},
	{1, 0, 0, 0},
	{1, 0, 0, 0},
	{1, 0, 0, 0},
	{1, 0, 0, 0},
	{1, 0, 0, 0},
	{1, 0, 0, 0},
	{1, 0, 0, 0},
	{1, 0, 0, 0},
	{2, 0, 0, 0},
	{2, 0, 0, 0},
	{2, 0, 0, 0},
	{2, 0, 0, 0},
	{3, 0, 0, 0},
	{3, 0, 0, 0},
	{3, 0, 0, 0},
	{3, 0, 0, 0},
	{4, 0, 0, 0},
	{4, 0, 0, 0},
	{3, 0, 0x2D, 0},
	{2, 0, 0x2E, 0},
	{5, 0, 0xD5, 0},
	{5, 0, 0x30, 0},
	{3, 0, 0x31, 0},
	{3, 0, 0x32, 0},
	{3, 0, 0x33, 0},
	{3, 0, 0x34, 0},
	{1, 1, 0x3A, 0},
	{1, 1, 0x3B, 0},
	{3, 1, 0x42, 0},
	{1, 1, 0x3D, 0},
	{2, 1, 0x3D, 1},
	{3, 1, 0x3D, 2},
	{3, 1, 0x42, 0},
	{3, 1, 0x42, 0},
	{1, 0, 0x44, 0},
	{3, 0, 0x46, 0},
	{2, 0, 0x0B9, 0},
	{1, 0, 0x43, 0},
	{3, 0, 0x42, 0},
	{2, 0, 0x29, 0},
	{3, 0, 0x2B, 0},
	{2, 0, 0x2A, 0},
	{4, 1, 0x42, 1},
	{1, 0, 0x40, 0},
	{3, 1, 0x0CD, 0},
	{3, 1, 0x42, 0},
	{2, 1, 0x11, 1},
	{2, 1, 0x11, 0},
	{2, 0, 0x47, 0},
	{2, 0, 0x48, 0},
	{2, 0, 0x49, 0},
	{2, 0, 0x4A, 0},
	{2, 0, 0x4B, 0},
	{3, 0, 0x47, 1},
	{3, 0, 0x48, 1},
	{3, 0, 0x49, 1},
	{3, 0, 0x4A, 1},
	{3, 0, 0x4B, 1},
	{2, 0, 0x16, 0},
	{3, 0, 0x63, 0},
	{1, 1, 0x52, 0},
	{1, 1, 0x52, 0},
	{2, 0, 0x4D, 0},
	{3, 0, 0x4E, 0},
	{2, 0, 0x4F, 0},
	{3, 0, 0x55, 0},
	{4, 0, 0x56, 0},
	{5, 0, 0x57, 0},
	{2, 1, 0x0B8, 0},
	{1, 1, 0x51, 0},
	{1, 1, 0, 0},
	{1, 1, 0, 0},
	{0, 0, 0, 0},
	{5, 0, 0x3E, 0},
	{2, 0, 0x3F, 0},
	{0, 0, 0, 0},
	{1, 1, 0x0B7, 0},
	{2, 1, 0x0B7, 2},
	{3, 1, 0x19, 0},
	{1, 1, 0x36, 0},
	{1, 1, 0x17, 0},
	{1, 1, 0x64, 0},
	{3, 0, 0x0C9, 0},
	{3, 0, 0x0A6, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{2, 0, 0x4C, 0},
	{1, 1, 0, 0},
	{3, 0, 0x25, 0},
	{3, 0, 0x25, 0},
	{3, 0, 0x25, 0},
	{3, 0, 0x25, 0},
	{3, 0, 0x25, 0},
	{3, 0, 0x25, 0},
	{2, 0, 0x26, 0},
	{2, 0, 0x27, 0},
	{2, 0, 0x41, 0},
	{2, 0, 0x28, 0},
	{2, 0, 0x2C, 0},
	{2, 0, 0x7A, 0},
	{2, 0, 0x7B, 0},
	{2, 0, 0x7C, 0},
	{2, 0, 0x7D, 0},
	{0, 0, 0, 0},
	{1, 1, 0, 0},
	{1, 1, 0, 0},
	{1, 1, 0, 0},
	{1, 1, 0, 0},
	{1, 1, 0, 0},
	{1, 1, 0, 0},
	{1, 1, 0, 0},
	{1, 1, 0, 0},
	{1, 1, 0, 0},
	{1, 1, 0, 0},
	{1, 1, 0, 0},
	{1, 1, 0, 0},
	{1, 1, 0, 0},
	{2, 1, 0x0D8, 0},
	{1, 1, 0, 0},
	{1, 1, 0, 0},
	{1, 1, 0, 0},
	{1, 1, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0}
};

const struct MissionId Constant_MissionIds[12] = {
	{0, 0},
	{1, 1},
	{2, 3},
	{4, 5},
	{6, 7},
	{8, 9},
	{10, 11},
	{12, 13},
	{14, 15},
	{16, 17},
	{18, 19},
	{20, 21},
};