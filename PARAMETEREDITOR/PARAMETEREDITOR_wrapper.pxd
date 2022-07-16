#cython: c_string_type=unicode, c_string_encoding=utf8

from cpython cimport float 

from libcpp cimport bool
from libcpp.string cimport string

cdef extern from "Simple_PARAMETER_EDITOR.h":
	cdef cppclass PARAMETEREDITOR:
		PARAMETEREDITOR()
		PARAMETEREDITOR(string, string, int, float, float, float, float, float, float, float, float, float, float, bool) except +
		void Simple_PARAMETER_EDITOR()
		int return_Data(unsigned int, bool)
		void enemy_Param_Editor()
		void write_Data(unsigned int, unsigned int, unsigned int, int, bool)
		int combine(int, int, int, int)
		float randomFloat(float, float)

		float scaleLow
		float scaleHigh
		float healthLow
		float healthHigh
		float speedLow
		float speedHigh
		float damageLow
		float damageHigh
		float knockbackPowerLow
		float knockbackPowerHigh
		bool randoScaleSeperate
		string inputLocation
		string outputLocation
		
