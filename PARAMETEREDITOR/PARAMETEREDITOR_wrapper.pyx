# distutils: language = c++
#cython: language_level=3
#cython: c_string_type=unicode, c_string_encoding=utf8

from libcpp cimport bool
from libcpp.string cimport string

from PARAMETEREDITOR_wrapper cimport PARAMETEREDITOR

cdef class PyPARAMETEREDITOR:
	cdef PARAMETEREDITOR *thisptr
	def __cinit__(self, string in_File, string out_File, int gen_Seed, float SCALE_L, float SCALE_H, float HEALTH_L, float HEALTH_H, float SPEED_L, float SPEED_H, float DAMAGE_L, float DAMAGE_H, float KNOCK_L, float KNOCK_H, bool Seperate):
		self.thisptr = new PARAMETEREDITOR(in_File, out_File, gen_Seed, SCALE_L, SCALE_H, HEALTH_L, HEALTH_H, SPEED_L, SPEED_H, DAMAGE_L, DAMAGE_H, KNOCK_L, KNOCK_H, Seperate)
	def __dealloc__(self):
		del self.thisptr
		
	def Simple_PARAMETER_EDITOR(self):
		self.thisptr.Simple_PARAMETER_EDITOR()
		
	def return_Data(self, hex_Data, small_Value):
		return self.thisptr.return_Data(hex_Data, small_Value)
		
	def enemy_Param_Editor(self):
		self.thisptr.enemy_Param_Editor()
		
	def write_Data(self, current_offset, randomized_Value, offset, conditional, object_ID):
		self.thisptr.write_Data(current_offset, randomized_Value, offset, conditional, object_ID)
		
	def combine(self, a, b, c, d):
		return self.thisptr.combine(a, b, c, d)
		
	def randomFloat(self, low, high):
		self.thisptr.randomFloat(low, high)
		
	property scaleLow:
		def __get__(self): return self.thisptr.scaleLow
		def __set__(self, scaleLow): self.thisptr.scaleLow = scaleLow
			
			
	property scaleHigh:
		def __get__(self): return self.thisptr.scaleHigh
		def __set__(self, scaleHigh): self.thisptr.scaleHigh = scaleHigh
			
			
	property healthLow:
		def __get__(self): return self.thisptr.healthLow
		def __set__(self, healthLow): self.thisptr.healthLow = healthLow
			
			
	property healthHigh:
		def __get__(self): return self.thisptr.healthHigh
		def __set__(self, healthHigh): self.thisptr.healthHigh = healthHigh
			
	property speedLow:
		def __get__(self): return self.thisptr.speedLow
		def __set__(self, speedLow): self.thisptr.speedLow = speedLow
			
	property speedHigh:
		def __get__(self): return self.thisptr.speedHigh
		def __set__(self, speedHigh): self.thisptr.speedHigh = speedHigh
			
	property damageLow:
		def __get__(self): return self.thisptr.damageLow
		def __set__(self, damageLow): self.thisptr.damageLow = damageLow
			
	property damageHigh:
		def __get__(self): return self.thisptr.damageHigh
		def __set__(self, damageHigh): self.thisptr.damageHigh = damageHigh
			
	property knockbackPowerLow:
		def __get__(self): return self.thisptr.knockbackPowerLow
		def __set__(self, knockbackPowerLow): self.thisptr.knockbackPowerLow = knockbackPowerLow
			
	property knockbackPowerHigh:
		def __get__(self): return self.thisptr.knockbackPowerHigh
		def __set__(self, knockbackPowerHigh): self.thisptr.knockbackPowerHigh = knockbackPowerHigh
			
	property randoScaleSeperate:
		def __get__(self): return self.thisptr.randoScaleSeperate
		def __set__(self, randoScaleSeperate): self.thisptr.randoScaleSeperate = randoScaleSeperate
		
	property inputLocation:
		def __get__(self): return self.thisptr.inputLocation
		def __set__(self, inputLocation): self.thisptr.inputLocation = inputLocation
		
	property outputLocation:
		def __get__(self): return self.thisptr.outputLocation
		def __set__(self, outputLocation): self.thisptr.outputLocation = outputLocation