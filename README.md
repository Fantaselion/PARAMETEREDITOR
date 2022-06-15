# PARAMETEREDITOR
Randomizes most enemy (and bosses) scale, health, speed, damage, and knockback power within a user defined range for the game "Metroid Prime"

Build instructions are written for windows but the linux version of them should work.

## Installing Python Module
```sh
> pip install PARAMETEREDITOR
> python
>>> import PARAMETEREDITOR
>>> PARAMETEREDITOR.PyPARAMETEREDITOR("input.iso", "output.iso", 601310422, 0.25, 4, 0.25, 4, 0.25, 4, 0.25, 4, 0.25, 4, True) # (Input, Output, Seed, ScaleLow, ScaleHigh, HealthLow, HealthHigh, SpeedLow, Speedhigh, DamageLow, DamageHigh, KnockbackPowerLow, KnockbackPowerHigh, RandoScaleXYZSeperatly)
```

## Python Build

```
python setup.py build_ext --inplace
```
