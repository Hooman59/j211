#ifndef ENUMS_H
#define ENUMS_H

enum varType
{
    T_ushort,
    T_short,
    T_uint,
    T_int,
    T_float,
    T_string

};

enum varKind
{
    CMD,
    Status,
    Settings,
    Input,
    Output,
    Local
};

enum BlockType
{
  B_Unknown,
  B_Security,
  B_Light,
  B_GenSafty,
  B_FireSafty,
  B_WaterCooler,
  B_OccupancyTemp,
  B_OccupancyLighting,
  B_GeneralLight,
  B_BarFanCoil,
  B_InternalValues,
  B_Calander,
  B_FB_ADD
};
#endif
