#include "stdafx.h"
#include <Windows.h>

struct DIRENTRY
{
	char name[20];
	long attr;
	long size;
	DIRENTRY* next;
	long head;
	char system[4];
};

struct SVECTOR
{
	short vx;
	short vy;
	short vz;
	short pad;
};

struct CVECTOR
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char cd;
};

struct DVECTOR
{
	short vx;
	short vy;
};

struct RVECTOR
{
	SVECTOR v;
	unsigned char uv[2];
	unsigned short pad;
	CVECTOR c;
	DVECTOR sxy;
	unsigned long sz;
};

struct RECT
{
	short x;
	short y;
	short w;
	short h;
};

struct DR_ENV
{
	unsigned long tag;
	unsigned long code[15];
};

struct PHD_VECTOR
{
	long x;
	long y;
	long z;
};

struct PHD_3DPOS
{
	long x_pos;
	long y_pos;
	long z_pos;
	short x_rot;
	short y_rot;
	short z_rot;
};

struct ILIGHT
{
	short x;
	short y;
	short z;
	short pad1;
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char pad;
};

struct ITEM_LIGHT
{
	ILIGHT Light[4];
};

struct ITEM_INFO
{
	long floor;
	unsigned long touch_bits;
	unsigned long mesh_bits;
	short object_number;
	short current_anim_state;
	short goal_anim_state;
	short required_anim_state;
	short anim_number;
	short frame_number;
	short room_number;
	short next_item;
	short next_active;
	short speed;
	short fallspeed;
	short hit_points;
	unsigned short box_number;
	short timer;
	short flags;
	short shade;
	short trigger_flags;
	short carried_item;
	short after_death;
	unsigned short fired_weapon;
	short item_flags[4];
	void* data;
	PHD_3DPOS pos;
	ITEM_LIGHT il;
	unsigned long active : 1;
	unsigned long status : 2;
	unsigned long gravity_status : 1;
	unsigned long hit_status : 1;
	unsigned long collidable : 1;
	unsigned long looked_at : 1;
	unsigned long dynamic_light : 1;
	unsigned long poisoned : 1;
	unsigned long ai_bits : 5;
	unsigned long really_active : 1;
	unsigned long InDrawRoom : 1;
	unsigned long meshswap_meshbits;
	short draw_room;
	short TOSSPAD;
};

struct MouseData
{
	unsigned short buttons;
	char xOffset;
	char yOffset;
};

struct NegconData
{
	unsigned short digitalButtons;
	char centralTwist;
	char buttonI;
	char buttonII;
	char topLeft;
};

struct GunConData
{
	unsigned short digitalButtons;
	unsigned char GunconX;
	unsigned char GunConScreenDiv;
	unsigned char GunconY;
	unsigned char pad;
};

struct AnalogjoyData
{
	unsigned short digitalButtons;
	unsigned char right_x;
	unsigned char right_y;
	unsigned char left_x;
	unsigned char left_y;
};

struct AnalogController
{
	unsigned short digitalButtons;
	unsigned char right_x;
	unsigned char right_y;
	unsigned char left_x;
	unsigned char left_y;
};

struct TapCtrllerData
{
	unsigned char transStatus;
	unsigned char dataFormat;
	union data;
};

struct MultiTapData
{
	TapCtrllerData ctrllers[4];
};

struct SpuVolume
{
	short left;
	short right;
};

struct FX_INFO
{
	PHD_3DPOS pos;
	short room_number;
	short object_number;
	short next_fx;
	short next_active;
	short speed;
	short fallspeed;
	short frame_number;
	short counter;
	short shade;
	short flag1;
	short flag2;
};

struct lara_arm
{
	short* frame_base;
	short frame_number;
	short anim_number;
	short lock;
	short y_rot;
	short x_rot;
	short z_rot;
	short flash_gun;
};

struct box_node
{
	short exit_box;
	unsigned short search_number;
	short next_expansion;
	short box_number;
};

enum mood_type
{
	BORED_MOOD,
	ATTACK_MOOD,
	ESCAPE_MOOD,
	STALK_MOOD
};

enum zone_type
{
	SKELLY_ZONE,
	BASIC_ZONE,
	CROC_ZONE,
	HUMAN_ZONE,
	FLYER_ZONE
};

struct lot_info
{
	box_node* node;
	short head;
	short tail;
	unsigned short search_number;
	unsigned short block_mask;
	short step;
	short drop;
	short zone_count;
	short target_box;
	short required_box;
	short fly;
	unsigned short can_jump : 1;
	unsigned short can_monkey : 1;
	unsigned short is_amphibious : 1;
	unsigned short is_jumping : 1;
	unsigned short is_monkeying : 1;
	PHD_VECTOR target;
	zone_type zone;
};

struct creature_info
{
	short joint_rotation[4];
	short maximum_turn;
	short flags;
	unsigned short alerted : 1;
	unsigned short head_left : 1;
	unsigned short head_right : 1;
	unsigned short reached_goal : 1;
	unsigned short hurt_by_lara : 1;
	unsigned short patrol2 : 1;
	unsigned short jump_ahead : 1;
	unsigned short monkey_ahead : 1;
	mood_type mood;
	ITEM_INFO* enemy;
	ITEM_INFO ai_target;
	short pad;
	short item_num;
	PHD_VECTOR target;
	lot_info LOT;
};

struct GAMEFLOW
{
	unsigned long CheatEnabled : 1;
	unsigned long LoadSaveEnabled : 1;
	unsigned long TitleEnabled : 1;
	unsigned long PlayAnyLevel : 1;
	unsigned long Language : 3;
	unsigned long DemoDisc : 1;
	unsigned long Unused : 24;
	unsigned long InputTimeout;
	unsigned char SecurityTag;
	unsigned char nLevels;
	unsigned char nFileNames;
	unsigned char Pad;
	unsigned short FileNameLen;
	unsigned short ScriptLen;
};

struct STRINGHEADER
{
	unsigned short nStrings;
	unsigned short nPSXStrings;
	unsigned short nPCStrings;
	unsigned short StringWadLen;
	unsigned short PSXStringWadLen;
	unsigned short PCStringWadLen;
};

struct TapCtrllerData
{
	unsigned char transStatus;
	unsigned char dataFormat;
	union data;
};

struct FLOOR_INFO
{
	unsigned short index;
	unsigned short fx : 4;
	unsigned short box : 11;
	unsigned short stopper : 1;
	unsigned char pit_room;
	char floor;
	unsigned char sky_room;
	char ceiling;
};

struct LIGHTINFO
{
	long x;
	long y;
	long z;
	unsigned char Type;
	unsigned char r;
	unsigned char g;
	unsigned char b;
	short nx;
	short ny;
	short nz;
	short Intensity;
	unsigned char Inner;
	unsigned char Outer;
	short FalloffScale;
	short Length;
	short Cutoff;
};

struct MESH_INFO
{
	long x;
	long y;
	long z;
	short y_rot;
	short shade;
	short Flags;
	short static_number;
};

struct room_info
{
	short* data;
	short* door;
	FLOOR_INFO* floor;
	LIGHTINFO* light;
	MESH_INFO* mesh;
	long x;
	long y;
	long z;
	long minfloor;
	long maxceiling;
	short x_size;
	short y_size;
	CVECTOR ambient;
	short num_lights;
	short num_meshes;
	unsigned char ReverbType;
	unsigned char FlipNumber;
	char MeshEffect;
	char bound_active;
	short left;
	short right;
	short top;
	short bottom;
	short test_left;
	short test_right;
	short test_top;
	short test_bottom;
	short item_number;
	short fx_number;
	short flipped_room;
	unsigned short flags;
};

struct ROPE_STRUCT
{
	PHD_VECTOR Segment[24];
	PHD_VECTOR Velocity[24];
	PHD_VECTOR NormalisedSegment[24];
	PHD_VECTOR MeshSegment[24];
	PHD_VECTOR Position;
	long SegmentLength;
	short Active;
	short Coiled;
};

struct PENDULUM
{
	PHD_VECTOR Position;
	PHD_VECTOR Velocity;
	int node;
	ROPE_STRUCT* Rope;
};

struct GAME_VECTOR
{
	long x;
	long y;
	long z;
	short room_number;
	short box_number;
};

struct object_info
{
	short nmeshes;
	short mesh_index;
	long bone_index;
	short* frame_base;
	void(*initialize);
	void(*control);
	void(*floor);
	void(*ceiling);
	void(*draw_routine);
	void(*collision);
	short object_mip;
	short sanim_index;
	short hit_points;
	short pivot_length;
	short radius;
	short shadow_size;
	unsigned short bite_offset;
	unsigned short loaded : 1;
	unsigned short intelligent : 1;
	unsigned short non_lot : 1;
	unsigned short save_position : 1;
	unsigned short save_hitpoints : 1;
	unsigned short save_flags : 1;
	unsigned short save_anim : 1;
	unsigned short semi_transparent : 1;
	unsigned short water_creature : 1;
	unsigned short using_drawanimating_item : 1;
	unsigned short HitEffect : 2;
	unsigned short undead : 1;
	unsigned short save_mesh : 1;
	void(*draw_routine_extra);
	unsigned long explodable_meshbits;
	unsigned long padfuck;
};

struct RAT_STRUCT
{
	PHD_3DPOS pos;
	short room_number;
	short speed;
	short fallspeed;
	unsigned char On;
	unsigned char flags;
};

struct BAT_STRUCT
{
	PHD_3DPOS pos;
	short room_number;
	short speed;
	short Counter;
	short LaraTarget;
	char XTarget;
	char ZTarget;
	unsigned char On;
	unsigned char flags;
};

struct SPIDER_STRUCT
{
	PHD_3DPOS pos;
	short room_number;
	short speed;
	short fallspeed;
	unsigned char On;
	unsigned char flags;
};

struct TWOGUN_INFO //Enemy that shoot Low-frequency Spiral railgun shit
{
	PHD_3DPOS pos;
	short life;
	short coil;
	short pin;
	short spinadd;
	short length;
	short dlength;
	short size;
	char r;
	char g;
	char b;
	char fadein;
};

struct CHARDEF //check_xray_machine_trigger function
{
	unsigned char u;
	unsigned char v;
	unsigned char w;
	unsigned char h;
	char YOffset;
	unsigned char TopShade;
	unsigned char BottomShade;
};

struct COLL_INFO //Collision Info !
{
	long mid_floor;
	long mid_ceiling;
	long mid_type;
	long front_floor;
	long front_ceiling;
	long front_type;
	long left_floor;
	long left_ceiling;
	long left_type;
	long right_floor;
	long right_ceiling;
	long right_type;
	long left_floor2;
	long left_ceiling2;
	long left_type2;
	long right_floor2;
	long right_ceiling2;
	long right_type2;
	long radius;
	long bad_pos;
	long bad_neg;
	long bad_ceiling;
	PHD_VECTOR shift;
	PHD_VECTOR old;
	short old_anim_state;
	short old_anim_number;
	short old_frame_number;
	short facing;
	short quadrant;
	short coll_type;
	short* trigger;
	char tilt_x;
	char tilt_z;
	char hit_by_baddie;
	char hit_static;
	unsigned short slopes_are_walls : 2;
	unsigned short slopes_are_pits : 1;
	unsigned short lava_is_pit : 1;
	unsigned short enable_baddie_push : 1;
	unsigned short enable_spaz : 1;
	unsigned short hit_ceiling : 1;
};

struct lara_info
{
	short item_number;
	short gun_status;
	short gun_type;
	short request_gun_type;
	short last_gun_type;
	short calc_fallspeed;
	short water_status;
	short climb_status;
	short pose_count;
	short hit_frame;
	short hit_direction;
	short air;
	short dive_count;
	short death_count;
	short current_active;
	short current_xvel;
	short current_yvel;
	short current_zvel;
	short spaz_effect_count;
	short flare_age;
	short BurnCount;
	short weapon_item;
	short back_gun;
	short flare_frame;
	short poisoned;
	short dpoisoned;
	short Anxiety;
	short wet[15];
	unsigned short flare_control_left : 1;
	unsigned short Unused1 : 1;
	unsigned short look : 1;
	unsigned short burn : 1;
	unsigned short keep_ducked : 1;
	unsigned short IsMoving : 1;
	unsigned short CanMonkeySwing : 1;
	unsigned short BurnBlue : 2;
	unsigned short Gassed : 1;
	unsigned short BurnSmoke : 1;
	unsigned short has_fired : 1;
	unsigned short Busy : 1;
	unsigned short LitTorch : 1;
	unsigned short IsClimbing : 1;
	unsigned short Fired : 1;
	long water_surface_dist;
	PHD_VECTOR last_pos;
	FX_INFO* spaz_effect;
	int mesh_effects;
	short* mesh_ptrs[15];
	ITEM_INFO* target;
	short target_angles[2];
	short turn_rate;
	short move_angle;
	short head_y_rot;
	short head_x_rot;
	short head_z_rot;
	short torso_y_rot;
	short torso_x_rot;
	short torso_z_rot;
	lara_arm left_arm;
	lara_arm right_arm;
	unsigned short holster;
	creature_info* creature;
	long CornerX;
	long CornerZ;
	char RopeSegment;
	char RopeDirection;
	short RopeArcFront;
	short RopeArcBack;
	short RopeLastX;
	short RopeMaxXForward;
	short RopeMaxXBackward;
	long RopeDFrame;
	long RopeFrame;
	unsigned short RopeFrameRate;
	unsigned short RopeY;
	long RopePtr;
	void* GeneralPtr;
	int RopeOffset;
	unsigned long RopeDownVel;
	char RopeFlag;
	char MoveCount;
	int RopeCount;
	char skelebob;
	char pistols_type_carried;
	char uzis_type_carried;
	char shotgun_type_carried;
	char crossbow_type_carried;
	char hk_type_carried;
	char sixshooter_type_carried;
	char lasersight;
	char silencer;
	char binoculars;
	char crowbar;
	char examine1;
	char examine2;
	char examine3;
	char wetcloth;
	char bottle;
	char puzzleitems[12];
	unsigned short puzzleitemscombo;
	unsigned short keyitems;
	unsigned short keyitemscombo;
	unsigned short pickupitems;
	unsigned short pickupitemscombo;
	short num_small_medipack;
	short num_large_medipack;
	short num_flares;
	short num_pistols_ammo;
	short num_uzi_ammo;
	short num_revolver_ammo;
	short num_shotgun_ammo1;
	short num_shotgun_ammo2;
	short num_hk_ammo1;
	short num_crossbow_ammo1;
	short num_crossbow_ammo2;
	char location;
	char highest_location;
	char locationPad;
	unsigned char TightRopeOnCount;
	unsigned char TightRopeOff;
	unsigned char TightRopeFall;
	unsigned char ChaffTimer;
};

struct MATRIX3D
{
	short m00;
	short m01;
	short m02;
	short m10;
	short m11;
	short m12;
	short m20;
	short m21;
	short m22;
	short pad;
	long tx;
	long ty;
	long tz;
};

struct ANIM_STRUCT
{
	short* frame_ptr;
	short interpolation;
	short urrent_anim_state;
	long velocity;
	long acceleration;
	long Xvelocity;
	long Xacceleration;
	short frame_base;
	short frame_end;
	short jump_anim_num;
	short jump_frame_num;
	short number_changes;
	short change_index;
	short number_commands;
	short command_index;
};

struct SPARKS
{
	long x;
	long y;
	long z;
	short Xvel;
	short Yvel;
	short Zvel;
	short Gravity;
	short RotAng;
	short Flags;
	unsigned char sSize;
	unsigned char dSize;
	unsigned char Size;
	unsigned char Friction;
	unsigned char Scalar;
	unsigned char Def;
	char RotAdd;
	char MaxYvel;
	unsigned char On;
	unsigned char sR;
	unsigned char sG;
	unsigned char sB;
	unsigned char dR;
	unsigned char dG;
	unsigned char dB;
	unsigned char R;
	unsigned char G;
	unsigned char B;
	unsigned char ColFadeSpeed;
	unsigned char FadeToBlack;
	unsigned char sLife;
	unsigned char Life;
	unsigned char TransType;
	unsigned char extras;
	char Dynamic;
	unsigned char FxObj;
	unsigned char RoomNumber;
	unsigned char NodeNumber;
};

struct RTDECODE
{
	unsigned long length;
	unsigned long off;
	unsigned short counter;
	unsigned short data;
	unsigned char decodetype;
	unsigned char packmethod;
	unsigned short padfuck;
};

struct PACKNODE
{
	short xrot_run;
	short yrot_run;
	short zrot_run;
	short xkey;
	short ykey;
	short zkey;
	RTDECODE decode_x;
	RTDECODE decode_y;
	RTDECODE decode_z;
	unsigned long xlength;
	unsigned long ylength;
	unsigned long zlength;
	char* xpacked;
	char* ypacked;
	char* zpacked;
};

struct NODELOADHEADER
{
	short xkey;
	short ykey;
	short zkey;
	short packmethod;
	short xlength;
	short ylength;
	short zlength;
};

struct RESIDENT_THING
{
	char* packed_data;
};

struct ACTORME
{
	int offset;
	short objslot;
	short nodes;
};

struct NEW_CUTSCENE
{
	short numactors;
	short numframes;
	int orgx;
	int orgy;
	int orgz;
	int audio_track;
	int camera_offset;
	ACTORME actor_data[10];
};

struct CUTSEQ_ROUTINES
{
	void(*init_func);
	void(*control_func);
	void(*end_func);
};

struct DOORPOS_DATA
{
	FLOOR_INFO* floor;
	FLOOR_INFO data;
	short block;
};

struct DOOR_DATA
{
	DOORPOS_DATA d1;
	DOORPOS_DATA d1flip;
	DOORPOS_DATA d2;
	DOORPOS_DATA d2flip;
	short Opened;
	short* dptr1;
	short* dptr2;
	short* dptr3;
	short* dptr4;
	char dn1;
	char dn2;
	char dn3;
	char dn4;
	ITEM_INFO* item;
};

struct CHANGE_STRUCT //ProcessClosedDoors
{
	short goal_anim_state;
	short number_ranges;
	short range_index;
};

struct RANGE_STRUCT //ProcessClosedDoors
{
	short start_frame;
	short end_frame;
	short link_anim_num;
	short link_frame_num;
};

struct door_vbuf
{
	long xv;
	long yv;
	long zv;
};

struct BITE_INFO
{
	long x;
	long y;
	long z;
	long mesh_num;
};

struct box_info
{
	unsigned char left;
	unsigned char right;
	unsigned char top;
	unsigned char bottom;
	short height;
	short overlap_index;
};

enum target_type
{
	NO_TARGET,
	PRIME_TARGET,
	SECONDARY_TARGET
};

struct AI_info
{
	short zone_number;
	short enemy_zone;
	long distance;
	long ahead;
	long bite;
	short angle;
	short x_angle;
	short enemy_facing;
};

struct AIOBJECT
{
	short object_number;
	short room_number;
	long x;
	long y;
	long z;
	short trigger_flags;
	short flags;
	short y_rot;
	short box_number;
};

struct OBJECT_VECTOR
{
	long x;
	long y;
	long z;
	short data;
	short flags;
};

enum camera_type
{
	CHASE_CAMERA,
	FIXED_CAMERA,
	LOOK_CAMERA,
	COMBAT_CAMERA,
	CINEMATIC_CAMERA,
	HEAVY_CAMERA
};

struct CAMERA_INFO
{
	GAME_VECTOR pos;
	GAME_VECTOR target;
	camera_type type;
	camera_type old_type;
	long shift;
	long flags;
	long fixed_camera;
	long number_frames;
	long bounce;
	long underwater;
	long target_distance;
	short target_angle;
	short target_elevation;
	short actual_elevation;
	short actual_angle;
	short lara_node;
	short box;
	short number;
	short last;
	short timer;
	short speed;
	short targetspeed;
	ITEM_INFO* item;
	ITEM_INFO* last_item;
	OBJECT_VECTOR* fixed;
	int mike_at_lara;
	PHD_VECTOR mike_pos;
};

struct SPHERE
{
	long x;
	long y;
	long z;
	long r;
};

struct SHATTER_ITEM
{
	SPHERE Sphere;
	ITEM_LIGHT* il;
	short* meshp;
	long Bit;
	short YRot;
	short Flags;
};

struct OLD_CAMERA
{
	short current_anim_state;
	short goal_anim_state;
	long target_distance;
	short target_angle;
	short target_elevation;
	short actual_elevation;
	PHD_3DPOS pos;
	PHD_3DPOS pos2;
	PHD_VECTOR t;
};

struct static_info
{
	short mesh_number;
	short flags;
	short x_minp;
	short x_maxp;
	short y_minp;
	short y_maxp;
	short z_minp;
	short z_maxp;
	short x_minc;
	short x_maxc;
	short y_minc;
	short y_maxc;
	short z_minc;
	short z_maxc;
};

struct PSXTEXTI
{
	unsigned char u0;
	unsigned char v0;
	unsigned short clut;
	unsigned char u1;
	unsigned char v1;
	unsigned short tpage;
	unsigned char u2;
	unsigned char v2;
	unsigned char codeGT4;
	unsigned char codeGT3;
	unsigned char u3;
	unsigned char v3;
	unsigned short pad3;
};

struct DEBRIS_STRUCT
{
	void* TextInfo;
	long x;
	long y;
	long z;
	short XYZOffsets1[3];
	short Dir;
	short XYZOffsets2[3];
	short Speed;
	short XYZOffsets3[3];
	short Yvel;
	short Gravity;
	short RoomNumber;
	unsigned char On;
	unsigned char XRot;
	unsigned char YRot;
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char Pad[2];
};

struct SPOTCAM
{
	long x;
	long y;
	long z;
	long tx;
	long ty;
	long tz;
	unsigned char sequence;
	unsigned char camera;
	short fov;
	short roll;
	short timer;
	short speed;
	short flags;
	short room_number;
	short pad;
};

struct QUAKE_CAM
{
	GAME_VECTOR spos;
	GAME_VECTOR epos;
};

struct DYNAMIC //Calculate Spot Cam ?
{
	long x;
	long y;
	long z;
	unsigned char on;
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned short falloff;
	unsigned char used;
	char pad1[1];
	long FalloffScale;
};

struct SP_DYNAMIC
{
	unsigned char On;
	unsigned char Falloff;
	unsigned char R;
	unsigned char G;
	unsigned char B;
	unsigned char Flags;
	unsigned char Pad[2];
};

struct SPLASH_STRUCT
{
	long x;
	long y;
	long z;
	short InnerRad;
	short InnerSize;
	short InnerRadVel;
	short InnerYVel;
	short InnerY;
	short MiddleRad;
	short MiddleSize;
	short MiddleRadVel;
	short MiddleYVel;
	short MiddleY;
	short OuterRad;
	short OuterSize;
	short OuterRadVel;
	char flags;
	unsigned char life;
};

struct RIPPLE_STRUCT
{
	long x;
	long y;
	long z;
	char flags;
	unsigned char life;
	unsigned char size;
	unsigned char init;
};

struct SPLASH_SETUP
{
	long x;
	long y;
	long z;
	short InnerRad;
	short InnerSize;
	short InnerRadVel;
	short InnerYVel;
	short pad1;
	short MiddleRad;
	short MiddleSize;
	short MiddleRadVel;
	short MiddleYVel;
	short pad2;
	short OuterRad;
	short outerSize;
	short OuterRadVel;
	short pad3;
};

struct FIRE_LIST
{
	long x;
	long y;
	long z;
	char on;
	char size;
	short room_number;
};

struct FIRE_SPARKS
{
	short x;
	short y;
	short z;
	short Xvel;
	short Yvel;
	short Zvel;
	short Gravity;
	short RotAng;
	short Flags;
	unsigned char sSize;
	unsigned char dSize;
	unsigned char Size;
	unsigned char Friction;
	unsigned char Scalar;
	unsigned char Def;
	char RotAdd;
	char MaxYvel;
	unsigned char On;
	unsigned char sR;
	unsigned char sG;
	unsigned char sB;
	unsigned char dR;
	unsigned char dG;
	unsigned char dB;
	unsigned char R;
	unsigned char G;
	unsigned char B;
	unsigned char ColFadeSpeed;
	unsigned char FadeToBlack;
	unsigned char sLife;
	unsigned char Life;
};

struct SMOKE_SPARKS
{
	long x;
	long y;
	long z;
	short Xvel;
	short Yvel;
	short Zvel;
	short Gravity;
	short RotAng;
	short Flags;
	unsigned char sSize;
	unsigned char dSize;
	unsigned char Size;
	unsigned char Friction;
	unsigned char Scalar;
	unsigned char Def;
	char RotAdd;
	char MaxYvel;
	unsigned char On;
	unsigned char sShade;
	unsigned char dShade;
	unsigned char Shade;
	unsigned char ColFadeSpeed;
	unsigned char FadeToBlack;
	char sLife;
	char Life;
	unsigned char TransType;
	unsigned char FxObj;
	unsigned char NodeNumber;
	unsigned char mirror;
};

struct BLOOD_STRUCT
{
	long x;
	long y;
	long z;
	short Xvel;
	short Yvel;
	short Zvel;
	short Gravity;
	short RotAng;
	unsigned char sSize;
	unsigned char dSize;
	unsigned char Size;
	unsigned char Friction;
	char RotAdd;
	unsigned char On;
	unsigned char sShade;
	unsigned char dShade;
	unsigned char Shade;
	unsigned char ColFadeSpeed;
	unsigned char FadeToBlack;
	char sLife;
	char Life;
	char Pad;
};

struct GUNSHELL_STRUCT
{
	PHD_3DPOS pos;
	short fallspeed;
	short room_number;
	short speed;
	short counter;
	short DirXrot;
	short object_number;
};

struct GUNFLASH_STRUCT
{
	MATRIX3D matrix;
	short on;
};

struct DRIP_STRUCT
{
	long x;
	long y;
	long z;
	unsigned char On;
	unsigned char R;
	unsigned char G;
	unsigned char B;
	short Yvel;
	unsigned char Gravity;
	unsigned char Life;
	short RoomNumber;
	unsigned char Outside;
	unsigned char Pad;
};

struct NODEOFFSET_INFO
{
	short x;
	short y;
	short z;
	char mesh_num;
	unsigned char GotIt;
};

struct SHOCKWAVE_STRUCT
{
	long x;
	long y;
	long z;
	short InnerRad;
	short OuterRad;
	short XRot;
	short Flags;
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char life;
	short Speed;
	short Temp;
};

struct HAIR_STRUCT
{
	PHD_3DPOS pos;
	PHD_VECTOR vel;
};

struct DISPLAYPU
{
	short life;
	short object_number;
};

struct INVOBJ //AddDisplayPickup
{
	short object_number;
	short yoff;
	short scale1;
	short yrot;
	short xrot;
	short zrot;
	short flags;
	short objname;
	unsigned long meshbits;
};

struct OBJLIST
{
	short invitem;
	unsigned short yrot;
	unsigned short bright;
};

struct RINGME
{
	int ringactive;
	int objlistmovement;
	int curobjinlist;
	int numobjectsinlist;
};

struct AMMOLIST
{
	short invitem;
	short amount;
	unsigned short yrot;
};

struct MENUTHANG
{
	int type;
	char* text;
};

struct COMBINELIST
{
	void(*combine_routine);
	short item1;
	short item2;
	short combined_item;
};

struct WEAPON_INFO
{
	short lock_angles[4];
	short left_angles[4];
	short right_angles[4];
	short aim_speed;
	short shot_accuracy;
	short gun_height;
	short target_dist;
	char damage;
	char recoil_frame;
	char flash_time;
	char draw_frame;
	short sample_num;
};

struct PISTOL_DEF
{
	short ObjectNum;
	char Draw1Anim2;
	char Draw1Anim;
	char Draw2Anim;
	char RecoilAnim;
};

struct SUBSUIT_INFO //Lara Submarine-Underwater suit
{
	short XRot;
	short dXRot;
	short XRotVel;
	short Vel[2];
	short YVel;
};

struct STATS
{
	unsigned long Timer;
	unsigned long Distance;
	unsigned long AmmoUsed;
	unsigned long AmmoHits;
	unsigned short Kills;
	unsigned char Secrets;
	unsigned char HealthUsed;
};

struct savegame_info
{
	short Checksum;;
	unsigned short VolumeCD;
	unsigned short VolumeFX;
	short ScreenX;
	short ScreenY;
	unsigned char ControlOption;
	unsigned char VibrateOn;
	unsigned char AutoTarget;
	lara_info Lara;
	STATS Level;
	STATS Game;
	short WeaponObject;
	short WeaponAnim;
	short WeaponFrame;
	short WeaponCurrent;
	short WeaponGoal;
	unsigned long CutSceneTriggered1;
	unsigned long CutSceneTriggered2;
	char GameComplete;
	unsigned char CurrentLevel;
	unsigned char CampaignSecrets[4];
	unsigned char TLCount;
};

struct SAMPLE_INFO
{
	short number;
	unsigned char volume;
	char radius;
	char randomness;
	char pitch;
	short flags;
};

struct SoundSlot
{
	int OrigVolume;
	int nVolume;
	int nPan;
	int nPitch;
	int nSampleInfo;
	unsigned long distance;
	PHD_VECTOR pos;
};

struct FOOTPRINT
{
	long x;
	long y;
	long z;
	short YRot;
	short Active;
};

struct VECTOR3D
{
	long x;
	long y;
	long z;
};

struct CdlLOC
{
	unsigned char minute;
	unsigned char second;
	unsigned char sector;
	unsigned char track;
};

struct CdlFILE
{
	CdlLOC pos;
	unsigned long size;
	char name[16];
};

struct SpuExtAttr
{
	SpuVolume volume;
	long reverb;
	long mix;
};

struct SpuCommonAttr
{
	unsigned long mask;
	SpuVolume mvol;
	SpuVolume mvolmode;
	SpuVolume mvolx;
	SpuExtAttr cd;
	SpuExtAttr ext;
};

struct VECTOR
{
	long vx;
	long vy;
	long vz;
	long pad;
};

struct DRAWENV
{
	RECT clip;
	short ofs[2];
	RECT tw;
	unsigned short tpage;
	unsigned char dtd;
	unsigned char dfe;
	unsigned char isbg;
	unsigned char r0;
	unsigned char g0;
	unsigned char b0;
	DR_ENV dr_env;
};

struct DISPENV
{
	RECT disp;
	RECT screen;
	unsigned char isinter;
	unsigned char isrgb24;
	unsigned char pad0;
	unsigned char pad1;
};

struct LINE_F2
{
	unsigned long tag;
	unsigned char r0;
	unsigned char g0;
	unsigned char b0;
	unsigned char code;
	short x0;
	short y0;
	short x1;
	short y1;
};

struct DB_STRUCT
{
	int current_buffer;
	unsigned long* ot;
	char* polyptr;
	char* curpolybuf;
	char* polybuf_limit;
	int nOTSize;
	int nPBSize;
	unsigned long* order_table[2];
	unsigned long* poly_buffer[2];
	unsigned long* pickup_ot;
	unsigned long* pickup_order_table[2];
	DRAWENV draw[2];
	DISPENV disp[2];
};

struct PSXTEXTSTRUCT
{
	unsigned long u0v0clut;
	unsigned long u1v1tpage;
	unsigned long u2v2pad;
	unsigned long u3v3pad;
};

struct PSXSPRITESTRUCT
{
	short x1;
	short y1;
	short x2;
	short y2;
	unsigned short clut;
	unsigned short tpage;
	unsigned char u1;
	unsigned char v1;
	unsigned char u2;
	unsigned char v2;
};

struct TEXTURE
{
	unsigned char u0;
	unsigned char v0;
	unsigned short clut;
	unsigned char u1;
	unsigned char v1;
	unsigned short tpage;
	unsigned char u2;
	unsigned char v2;
	unsigned char id[2];
	unsigned char u3;
	unsigned char v3;
	unsigned short wclut;
};

struct MMTEXTURE
{
	TEXTURE t[3];
};

struct TSV
{
	unsigned long xy;
	unsigned long rgz;
};

struct ControllerPacket //CreateMonoScreen ?
{
	unsigned char transStatus;
	unsigned char dataFormat;
	union data;
};

struct pad_configs
{
	unsigned long pad_L2;
	unsigned long pad_R2;
	unsigned long pad_L1;
	unsigned long pad_R1;
	unsigned long pad_triangle;
	unsigned long pad_square;
	unsigned long pad_circle;
	unsigned long pad_cross;
};

struct GouraudBarColourSet
{
	unsigned char abLeftRed[5];
	unsigned char abLeftGreen[5];
	unsigned char abLeftBlue[5];
	unsigned char abRightRed[5];
	unsigned char abRightGreen[5];
	unsigned char abRightBlue[5];
};

struct STASHEDOBJ
{
	short clip;
	short numnodestodraw;
	ITEM_INFO* item;
	short* frmptr0;
};

struct STASHEDDAT
{
	short* mesh;
	char matrix[32];
};

struct WATERTAB
{
	char shimmer;
	char choppy;
	unsigned char random;
	unsigned char abs;
};

struct LINE_G2
{
	unsigned long tag;
	unsigned char r0;
	unsigned char g0;
	unsigned char b0;
	unsigned char code;
	short x0;
	short y0;
	unsigned char r1;
	unsigned char g1;
	unsigned char b1;
	unsigned char p1;
	short x1;
	short y1;
};

struct VIBRATION
{
	short Rate;
	short Len;
	short Lev;
	short Acc;
	short Dec;
	short Sus;
	short Flag;
	short Vib;
};

struct REQUESTER
{
	unsigned short TitleTxt;
	unsigned short TitleCol : 5;
	unsigned short nOptions : 3;
	unsigned short CursorPos : 3;
	unsigned short OptionCol : 5;
	unsigned long JustifyL : 5;
	unsigned long JustifyR : 5;
	unsigned long Arrows : 5;
	unsigned long Ignore : 5;
	unsigned short OptionTxt[5];
};

struct SCALE //DisplayStatsUCunt
{
	short xgrid;
	char scalefactor;
	char nummarks;
};

struct COCKSUCK
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char pad;
	short finalcnt;
	short profile_xcnt;
};

struct SpuVoiceAttr
{
	unsigned long voice;
	unsigned long mask;
	SpuVolume volume;
	SpuVolume volmode;
	SpuVolume volumex;
	unsigned short pitch;
	unsigned short note;
	unsigned short sample_note;
	short envx;
	unsigned long addr;
	unsigned long loop_addr;
	long a_mode;
	long s_mode;
	long r_mode;
	unsigned short ar;
	unsigned short dr;
	unsigned short sr;
	unsigned short rr;
	unsigned short sl;
	unsigned short adsr1;
	unsigned short adsr2;
};

struct PACKEDNAME
{
	unsigned char Days;
	unsigned char Hours;
	unsigned char Min;
	unsigned char Sec;
	unsigned short Slot;
	unsigned char Level;
	unsigned char Pad;
};

struct POLY_FT4
{
	unsigned long tag;
	unsigned char r0;
	unsigned char g0;
	unsigned char b0;
	unsigned char code;
	short x0;
	short y0;
	unsigned char u0;
	unsigned char v0;
	unsigned short clut;
	short x1;
	short y1;
	unsigned char u1;
	unsigned char v1;
	unsigned short tpage;
	short x2;
	short y2;
	unsigned char u2;
	unsigned char v2;
	unsigned short pad1;
	short x3;
	short y3;
	unsigned char u3;
	unsigned char v3;
	unsigned short pad2;
};