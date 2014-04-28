Sikkmod v1.2

by Sikkpin

sikkpin@hotmail.com


//=================================================================================
// About: 
//=================================================================================

Sikkmod is a general enhancement mod for id Software's 2004 FPS: Doom 3. Its main
purposes are to update visuals of Doom 3 to a more modern level and to allow the user
to customize various aspects of the game to suit their preferred styles all while 
maintaining the core mechanics and aesthetics originally put in by id Software.

The mod also includes a number of fixes to and better organization of stock files in order
to create a clean and more stable base for future mods.




//=================================================================================
// Installation:
//=================================================================================

Simply extract the "sikkmod" folder into your Doom 3 directory. That's all I'm going to say.

The mod can be loaded in two ways.
1) is to load it through the "Mods" main menu item.
2) is to use a custom shortcut to load it directly. You do this by creating a new
   shortcut for your "Doom3.exe". Right-click on it and select "Properties". Click
   on the "Shortcut" tab and in the "Target:" field put this:

	+set fs_game sikkmod

   after "...\Doom3.exe"

   Example: "C:\Games\Doom 3\Doom3.exe" +set fs_game sikkmod





//=================================================================================
// Files:
//=================================================================================

readme.txt	   	- this filed you are reading.

description.txt	   	- file used by the game so this mod shows up in the "Mods" menu.

mycurrentsettings.cfg	- contains the current sikkmod settings I use at the time of this writing

game00.pk4	  	- contains the "gamex86.dll"

pak_blankfiles.pk4	- contains all declaration files whose contents have either been moved
		   	  to a more appropriate file or removed entirely if the content was 
	           	  broken/incomplete or otherwise unusable. These files are only used to 
		   	  overwrite the base files of the same name to remove warnings in the console.

pak_cleanfiles.pk4	- contains all declaration files (and a few scripts/maps/textures) that have
		    	  been cleaned/formatted/fixed but don't have any mod-related changes to them.

pak_modfiles.pk4	- contains all mod-related files, either new files made for the mod or stock
		     	  files that have changes/addition made specifically for the mod.

sikkmod.ico	  	- sikkmod icon

sikkmod_v1.2-D3_src.rar	- contains the source code


//=================================================================================
// User's Guide:
//=================================================================================

With version 1.2, all tweaks/changes can now be configured through the menu except for the following:

- tweaked ammo pickup values to better reflect the amount that is visible on the model.
  	grenade pickup gives you 4 instead of 5
	a single machinegun clip gives you 30 and the double clip gives you 60
	small rocket pack gives you 4 and the large gives you 8

- weapons use variable zoom values

- All models have self shadowing enabled with md5 meshes having a shadow mesh built into the
  model. A few other various materials (mainly Hell materials) also have self shadowing enabled.

- Trent Reznor's sounds are used for the following:
	weapons: fists, pistol, shotgun, machine gun, chain gun
	monsters: zombies, zombie commandos, pinky demon


So, aside from those things listed above, all other features can be enabled/disabled/tweaked
through the sikkmod menu and/or console.





//=================================================================================
// Change Log:
//=================================================================================

v1.2:

- Gameplay:
-------------
 - Added a cvar to select between normal, Doom, and custom max armor values. The values used  are
   set through their respective def files.

 - Added a cvar to select between normal, Doom, and custom ammo capacity values. The values used  are
   set through their respective def files.

 - Added a cvar to select between normal, Doom, and custom ammo clip size values. The values used  are
   set through their respective def files.

 - Added a cvar to toggle weapon awareness. Having weapon awareness on also reduces spread/recoil
   while zoomed in.

 - Added a cvar to select weapon handling type meaning what kind of spread/recoil to use. Fixed means
   the the values are fixed and variable means that the values increase as you continue firing. The 
   mechanic is very basic but it works well enough for Doom 3 gameplay.

 - Added a cvar to toggle the origin point where the player's weapon projectile is launched from.
   Default means it uses what's defined in the weapon's def and "From Barrel", of course, means all
   projectiles are launched from the weapon's barrel. The Precise crosshair works with both methods.

 - Added a cvar to toggle player fall damage on/off.

 - Added a cvar to set the player's movement speed. 0(Doom 3) and 1(Doom 1&2) are hard coded. 2(Custom)
   means it uses the values that are set in "pm_crouchspeed", "pm_walkspeed", and "pm_runspeed" cvars.

 - Added a cvar to select between normal, Doom, and custom damage values. The values used  are
   set through their respective def files. The Doom 1 & 2 values use the same math as use in the 
   original Doom games.

 - Added a cvar to select between normal, Doom, and custom locational damage scale values. The values used
   are set through their respective def files. Doom 1 & 2 mode means there's no locational damage.

 - Added a cvar to select between normal, Doom, and custom enemy health values. The values used are
   set through their respective def files.

 - Added a cvar to select between normal, Doom, and custom weapon damage values. The values used  are
   set through their respective def files. The cvar also changes enemy damage values.

 - Added a new monster: Spectre. Basically just a pink demon with a custom skin. It randomly replaces 
   the normal pinky based on value of "g_enemySpectreFactor".

 - Added two monsters from revility's Demon Expansion Pack: The Baron of Hell and Pain Elemental. The Baron
   randomly replaces the Hellknight and the Pain Elemental randomly replaces the Cacodemon. Thier appearance
   factor is controlled by the cvars: "g_enemyBaronFactor" and "g_enemyPainElementalFactor", respectively.

 - Cyberdemon no longer takes splash damage when "Cyberdemon Damage Type" is set to "All Weapons", like in
   the original Doom games.

 - Fixed "Precise" crosshair. It's completely accurate now for all weapons.

 - Added Chainsaw Stickage™. This is to mimic the behavior of the Doom chainsaw where the view
   follows the monsters being chainsawed. Should make chainsawing lost souls and other monsters easier.

 - Monsters now have a "pain chance" while hacking them up with the chainsaw. The pain animation overrides
   their melee attack similar to how it is in Doom 1 & 2. This is to make the chainsaw a more viable weapon 
   and, not to mention, much more fun to use.

 - Removed the chainsaw's need for plasma fuel.
   


- Graphics:
-------------
 - Fixed sun shafts shader.

 - Fixed/improved a number of ao shaders. HBAO (low, medium, and high), ray marching, and vo have
   all been touched to either work better or to actually work correctly.

 - Improved the look of the explosion radial blur shader.

 - Some minor tweaks to the interaction shaders that will hopefully improve performance some.

 - Went through every shader and fixed/tweaked various things where needed.

 - Added a number of replacement interaction shaders that use various parallax methods. These are
   to maintain mod compatibility for those who are using high-res texture packs with heightmap support.
   It is recommended to use one of these shaders as opposed to the ones that come with any of the 
   texture packs.

 - Reverted all of the glass materials to their default states, so no more glass specular.


- Interface:
-------------
 - Updated main menu with the new cvars

 - Added a cvar to select between the use of Doom 3's default hud gui and the custom Alpha hud. One
   thing to note is that "g_useDynamicHud" only effects the Alpha hud.



- Misc:
-------------

 - Added a cvar to select between the use of Doom 3's default player head model and the marine helmet
   as the player's head.

 - Moveable items now have collision sound effects.

 - Fixed a bug in Delta1 where the outer ring of the reactor would move into place due to colliding
   with a medkit.

*Note: 	Again, this list is probably not 100% complete. Since it's just me working on this, I tend not
	to document every little change I make.



v1.1:

- Gameplay:
-------------
 - Added a "Use" function. This is used to pick up moveable objects(g_grabMode = 1), 
   pick up items(g_itemPickupType = 1), and to search corpses for items(g_itemSearchFactor > 0), 

 - Adrenaline power up is now carriable with "_impulse26" to use it. It now has the effect of
   cutting damage in half as well as infinite stamina.

 - Added the ablility to carry health packs (g_healthManagementType = 1). "_impulse25" to use
   health pack. The "g_healthPack*" cvars are used to customize the mechanic.

 - Using "g_itemRemovalFactor", items can be randomly removed upon map load, just to add 
   some randomization

 - Using "g_itemHelmetFactor", security armor will be randomly replaced with a new armor item:
   "Marine Helmet". This has an armor value of 25.

 - Using "g_itemValueFactor, each item's value will be randomly set. Like the variables above, 
   this is just to add some randomization and re-playability.

 - All items now have physics. There may be some items here and there that are "sinking" into
   ground but they should still be obtainable, this mostly happens with items on the bottom
   shelf of storage cabinets.

 - Made further tweaks to max ammo capacities

 - Added a cvar to toggle between normal ammo capacity values (max and clip size) and custom values

 - Changed max armor capacity to 50

 - Some minor tweaks to weapon damages for better balancing

 - Increased chaingun's rate of fire

 - Accuracy is increased when zoomed in and Weapon Handling Type is set to "Realistic"

 - Splash damage is now added on top of direct damage.

 - Increased the locational damage scale for "chest" do to some difficulty complaints (the
   previous scale kind of bothered me, as well)

 - Decreased the locational damage scale for "head" for the pinky demon and cacodemon as they
   were a little to easy to kill with the previous scale

 - Added a toggle for whether the Cyberdemon can be damaged by normal weapons.

 - Added a toggle for whether enemies of the same rank will fight each other.

 - Adjusted the volume and distance variable of the pinky demon's combat chatter sounds

 - Removed the crude random zombie script and implemented a better random spawning system
   via code. It's still in its infancy but it works good enough for now and its not limited 
   to just zombies.


- Graphics:
-------------
 - Updated and improved HDR implementation

 - Added HDR dynamic lens flare effect

 - Added color grading through the use of a lut. Much faster and more versatile than using math

 - Added Bokeh! ;)

 - Added an accumulation buffer style motion blur

 - Improved the look of the soft shadows with using Box or Poisson blur methods

 - Added localized radial blur effect from explosions

 - Added a frost build up effect on the screen when in outdoor areas

 - All new interaction shader using linear-space lighting, normalized Blinn-Phong
   specular model

 - miscellaneous tweaks and improvements to most shaders


- Interface:
-------------
 - updated, of course, to include all new cvars

 - made the sikkmod options menu more pretty.

 - setting "g_useDynamicHud" allows the hud to fade when stats are static for a period of time.
   Pressing "reload" will manually show the hud.


*Note: This list was made right before the release so it probably doesn't contain everything
       that's new or been changed. I'm too lazy to keep a change log as I go.

v1.0:
 - Initial Release




//=================================================================================
// Binds:
//=================================================================================

_impulse40	= Use

_impulse23 	= Headlight

_impulse24 	= IR Goggles

_impulse25 	= Health Pack

_impulse26 	= Adrenaline




//=================================================================================
// CVARs
//=================================================================================

// Gameplay Related CVARs
//-------------------------------
g_crosshair			0 = crosshair off, 1 = crosshair on, 2 = crosshair on only when zoomed or npc has focus
g_crosshairType			toggle between static and precise crosshair positioning
g_crosshairLerp			smoothness for the movement of the crosshair when g_crosshairType = 1

g_hudType			toggles between default and custom hud
g_useDynamicHud			enables dynamic hud
g_dynamicHudTime		time (in sec) before the hud fades out

g_goggleType			sets the goggle's type: 0 = Infrared; 1 = Thermal
g_batteryLife			how long the battery lasts (in seconds) for ir goggles/headlight
g_batteryRechargeRate		how long it takes the battery to fully recharge (in seconds) for ir goggles/headlight

g_useAmbientLight		enable a global ambient light bound to player
g_ambientLightRadius		sets the ambient light's radius (XYZ = 0 to 65536)
g_ambientLightColor		sets the ambient light's color (RGB = 0.0 to 1.0)

g_useExplosionFX		enables explosion screen effects
g_explosionFXTime		time (in secs) the effect lasts
g_explosionFXScale		explosion effect scale

g_showBloodSpray		show blood spray effect on screen when inflicting damage up close
g_bloodSprayTime		how long blood spray effect lasts (in seconds)
g_bloodSprayDistance		how close you have to be for blood spray effect to "hit the camera". Not relevant for chainsaw.
g_bloodSprayFrequency		how often the blood spray effect can occur. Value Range: 0.0 (never) - 1.0 (always)

g_screenFrostTime		time (in secs) for frost to fully build on the screen. 0 = disables effect

g_tracerFrequency		how frequent a fired shot will be a tracer. Value Range: 0.0 (no tracers) - 1.0 (all tracers)

g_playerHeadType		sets which head def to use for the player. 0 = Default Player Head; 1 = Marine Helmet

g_showFirstPersonBody		draws the player body in first person view mode

g_enablePortalSky		enables portal sky box support



g_healthManagementType		selects which health management system to use. 0 = default; 1 = carriable health pack; 2 = regenerating health
g_healthPackTotal		total amount of health reserve in the health pack
g_healthPackUses		number of uses in the health pack. g_healthPackTotal divided by this is how much health is given per use.
g_healthPackTime		maximum time it takes to heal yourself. 
g_healthRegenTime		how often to regenerate health when using regenerative health system
g_healthRegenDelay		delay (in seconds) before health starts to regenerate after taking damage when using regenerative health system
g_healthRegenAmt		how much health to regenerate per g_healthRegenTime when using regenerative health system
g_healthRegenLimit		total amount of health that can be regenerated when using regenerative health system
g_healthRegenSteps		splits g_healthRegenLimit into n number of steps. Value of 1 or less will turn steps off. example1: if g_healthRegenLimit == 100 && g_healthRegenSteps == 4, health regeneration will stop at 25/50/75/100; example2: if g_healthRegenLimit == 50 && g_healthRegenSteps == 5, health regeneration will stop at 10/20/30/40/50
g_healthRegenFeedback		how low must health reach before feedback is drawn when using regenerative health system

g_itemPickupType		toggles whether items need to be picked up manually with the 'Use' key.
g_itemMaxArmorType		sets armor capacity type: 0 = Doom 3; 1 = Doom 1/2; 2 = Custom
g_itemHelmetFactor		sets the factor for which security armor is randomly replaced with a marine helmet. Value Range: 0.0 (no replacement) - 1.0 (full replacement)
g_itemValueFactor		sets the factor for which the value for items are randomly set. Value Range: 0.0 (items have full value) - 1.0 (items have anywhere from one to full value)
g_itemRemovalFactor		sets the factor for which items are randomly removed from the map. Value Range: 0.0 (no items are removed) - 1.0 (all items are removed)
g_itemSearchFactor		sets the factor for which items can be found on dead bodies. Value Range: 0.0 (dead bodies contain no items) - 1.0 (dead bodies always contain items)

g_ammoCapacityType		sets ammo capacity type: 0 = Doom 3; 1 = Doom 1/2; 2 = Custom
g_ammoClipSizeType		sets ammo clip size type: 0 = Doom 3; 1 = Doom 1/2; 2 = Custom
g_ammoUsageType			enables realistic ammo usage when reloading and collecting ammo

g_weaponAwareness		toggles weapon awareness. This also determines whether recoil/spread is reduced while aiming.
g_weaponHandlingType		toggles between normal and realistic weapon handling
g_weaponProjectileOrigin	sets whether projectiles are launched from their def defined origin or to launch all projectiles from the weapon's barrel: 0 = Default; 1 = Weapon Barrel

g_grabMode			enables the ability to grab moveable objects

g_disableFallDamage		disables fall damage

g_playerSpeedType		sets the player's speed configuration: 0 = Doom 3; 1 = Doom 1/2; 2 = Custom

g_damageType			sets damage value type: 0 = Doom 3; 1 = Doom 1/2; 2 = Custom
g_damageZoneType		sets locational damage type: 0 = Doom 3; 1 = Doom 1/2; 2 = Custom

g_enemyHealthType		sets enemy health type: 0 = Doom 3; 1 = Doom 1/2; 2 = Custom
g_enemyHealthScale		sets the health scale for enemies
g_enemyHealthRandom		sets whether to randomize enemy health values

g_enemySpectreFactor		sets the factor that a Pinky demon will spawn as a Spectre
g_enemyPainElementalFactor	sets the factor that a Cacodemon will spawn as a Pain Elemental
g_enemyBaronFactor		sets the factor that a Hellknight will spawn as a Baron of Hell

g_burnAwayDelay			enemy burn away delay. 0.0 = use default value

g_interRankAggression		sets whether enemies of the same rank will fight each other

g_cyberdemonDamageType		sets how the Cyberdemon can be damaged: 0 = Soul Cube only; 1 = All weapons

g_zombieResurrectionLimit	sets the total number of times a zombie can resurrect. The chance for a zombie to resurrect is still randomized. 0 = Off

g_useRandomEncounters		enables random encounters
g_randomEncountersMaxSpawns	number of random enemies that can be alive at one time
g_randomEncountersMinTime	minimum time (in secs) to wait before spawning another random enemy
g_randomEncountersMaxTime	maximum time (in secs) to wait before spawning another random enemy
g_randomEncountersDormantTime	maximum time (in secs) a random enemy can be dormant before it is removed



// Player Related CVARs
//-------------------------------
pm_thirdPersonOffset		camera offset from player in 3rd person (-n = left, +n = right)



// Rendering Related CVARS
//-------------------------------
r_useSoftShadows		Enable Soft Shadows postprocessing effect
r_softShadowsBlurFilter		Blur method used for the shadow mask: 0 = No Filter; 1 = Box Filter; 2 = Poisson Filter; 3 = Gaussian Filter
r_softShadowsBlurScale		Sample offset scale for the blur filter
r_softShadowsBlurEpsilon	Set the blur depth difference factor for the blur filter

r_useEdgeAA			Enable edge anti-aliasing: 0 = RGB edge AA; 1 = FXAA
r_edgeAASampleScale		Set the sample offset scale for edge detection
r_edgeAAFilterScale		Set the filter offset scale for blurring

r_useHDR			Enable High Dynamic Range lighting
r_hdrToneMapper			Tone mapping method: 0 = Reinhard (RGB); 1 = Reinhard (Yxy); 2 = Exponential; 3 = Filmic (simple); 4 = Filmic (complex)
r_hdrAdaptationRate		Eye adaptation rate
r_hdrMiddleGray			Middle gray value used in HDR tone mapping
r_hdrWhitePoint			Smallest luminance value that will be mapped to white
r_hdrBlueShiftFactor		Blue shift blend factor
r_hdrDither			Enable dithering
r_hdrDitherSize			Sets the size of the dither threshold map
r_hdrLumThresholdMax		Minimum luminance value threshold
r_hdrLumThresholdMin		Maximum luminance value threshold
r_hdrBloomToneMapper		Tone mapping method, specific to bloom: 0 = Reinhard (RGB); 1 = Reinhard (Yxy); 2 = Exponential; 3 = Filmic (simple); 4 = Filmic (complex)
r_hdrBloomMiddleGray		Middle gray value used in HDR tone mapping, specific to bloom
r_hdrBloomWhitePoint		Smallest luminance value that will be mapped to white, specific to bloom
r_hdrBloomThreshold		Bloom luminance threshold
r_hdrBloomOffset		Bloom luminance offset
r_hdrBloomScale			Intensity scale amount for bloom effect
r_hdrBloomSize			Size of the bloom effect
r_hdrFlareGamma			Gamma curve for the flare texture
r_hdrFlareScale			Intensity scale amount for lens flare effect. 0 = Off
r_hdrFlareSize			Size of the lens flare effect
r_hdrGlareStyle			Glare Style to use with HDR lighting. Value range: 0 - 11
					0 = Off
					1 = Natural
					2 = Star
					3 = Cross
					4 = Snow Cross
					5 = Horizontal
					6 = Vertical
					7 = Star (Spectral)
					8 = Cross (Spectral)
					9 = Snow Cross (Spectral)
					10 = Horizontal (Spectral)
					11 = Vertical (Spectral)
r_hdrGlareScale			Intensity scale amount for glare effect
r_hdrGlareSize			Size of the glare effect

r_useBloom			Enable bloom postprocessing effect
r_bloomBufferSize		Bloom render target size:; 0 = 32x32; 1 = 64x64; 2 = 128x128; 3 = 256x256; 4 = 512x512; 5 = 1024x1024
r_bloomBlurIterations		Number of times the blur filter is applied
r_bloomBlurScaleX		Amount to scale the X axis sample offsets
r_bloomBlurScaleY		Amount to scale the Y axis sample offsets
r_bloomScale			Amount to scale the intensity of the bloom effect
r_bloomGamma			Gamma curve for the bloom texture

r_useSSIL			Enable Screen-Space Indirect Lighting postprocessing effect *Experimental*
r_ssilRadius			Set the sample radius for ssil
r_ssilAmount			Set the contribution factor for ssil
r_ssilBlurMethod		Blur method used for the ssil buffer: 0 = Gaussian; 1 = Bilateral
r_ssilBlurScale			Set the blur scale for the ssil buffer
r_ssilBlurQuality		Set the blur quality for the ssil buffer
r_ssilBlurEpsilon		Set the blur depth difference factor for the ssil buffer

r_useSSAO			Enable Screen-Space Ambient Occlusion postprocessing effect
r_ssaoMethod			Set the ssao method: 0 = Crytek; 1 = HDAO; 2 = ABAO; 3 = PBAO; 4 = HBAO (low); 5 = HBAO (medium); 6 = HBAO (high); 7 = Ray Marching; 8 = Volumetric Obscurance
r_ssaoRadius			Set the sample radius for ssao
r_ssaoBias			Set the angle bias for ssao (darkening factor for Crytek's)
r_ssaoAmount			Set the contribution factor for ssao
r_ssaoBlurMethod		Blur method used for the ssao buffer: 0 = Crytek; 1 = Box; 2 = Gaussian; 3 = Bilateral
r_ssaoBlurScale			Set the blur scale for the ssao buffer
r_ssaoBlurQuality		Set the blur quality for the ssao buffer
r_ssaoBlurEpsilon		Set the blur depth difference factor for the ssao buffer
r_ssaoBlendPower		Set the blend exponent for the ssao to scene final combine
r_ssaoBlendScale		Set the blend scale for the ssao to scene final combine

r_useSunShafts			Enable Screen-Space Volumetric Lighting (Sun Shafts) postprocessing effect *Experimental*
r_sunShaftsSize			Set the sun shafts size
r_sunShaftsStrength		Set the sun shafts strength
r_sunShaftsMaskStrength		Set the sun shafts mask strength
r_sunShaftsQuality		Set the sun shafts quality
r_sunOriginX			Set the sun's origin along the X axis (used for sun shafts & lens flare)
r_sunOriginY			Set the sun's origin along the Y axis (used for sun shafts & lens flare)
r_sunOriginZ			Set the sun's origin along the Z axis (used for sun shafts & lens flare)
r_useLensFlare			Enable lens flare postprocessing effect *Experimental*
r_lensFlareStrength		Set the lens flare strength

r_useDepthOfField		Enable depth of field postprocessing effect. Value range: 0 - 2; 0 = Off; 1 = Automatic Focus; 2 = Manual Focus
r_dofBlurScale			Set the blur scale for depth of field postprocessing effect
r_dofBlurQuality		Set the blur quality for depth of field postprocessing effect: 0 = Box Filter; 1 = Poisson Filter; 2 = Gaussian Filter; 3 = Bokeh!
r_dofNear			Set the near distance for depth of field postprocessing effect (r_useDepthOfField = 2 only)
r_dofFar			Set the far distance for depth of field postprocessing effect (r_useDepthOfField = 2 only)
r_dofFocus			Set the focus distance for depth of field postprocessing effect (r_useDepthOfField = 2 only)
r_dofConditionAlways		Depth of field condition: Always on
r_dofConditionCinematic		Depth of field condition: Cinematics
r_dofConditionGUI		Depth of field condition: GUI Active
r_dofConditionReload		Depth of field condition: Reloading
r_dofConditionTalk		Depth of field condition: Talking
r_dofConditionZoom		Depth of field condition: Weapon Zoom

r_useMotionBlur			Enable motion blur postprocessing effect. 0 = off; 1 = Camera; 2 = Accumulation; 3 = Camera + Accumulation
r_motionBlurScale		Set the motion blur scale. Works similar to shutter speed. Higher values == stronger blurring
r_motionBlurMaskDistance	Don't do motion blur if framerate is below this value
r_motionBlurFPSThreshold	Set the motion blur mask distance. Used to mask the view weapon.
r_motionBlurMinThreshold	Set the motion blur min sensitivity threshold. Screen won't blur until threshold is passed. Lower values == higher sensitivity
r_motionBlurMaxThreshold	Set the motion blur max sensitivity threshold. Blur strength won't pass threshold.
r_motionBlurFactor		Set the motion blur blend factor
r_motionBlurLerp		Set the motion blur blend lerp factor
r_motionBlurQuality		Set the motion blur quality. Value range: 1 - 4; 1 = 8 samples; 2 = 64 samples (virtual); 3 = 512 samples (virtual); 4 = 4096 samples (virtual)

r_useColorGrading		Enable color grading postprocessing effect. Parameters need to be set manually in the material.
r_colorGradingParm		Parameter to allow specific color grading stage to be used in the material
r_colorGradingType		Color grading type: 0 = math; 1 = lut
r_colorGradingSharpness		Sharpness level when color grading is enabled

r_useCelShading			Enable cel shading postprocessing effect
r_celShadingMethod		Set the cel shading edge detection method. Value range: 0 - 2 ; 0 = RGB; 1 = Luminance; 2 = Depth(incomplete)
r_celShadingScale		Set the cel shading scale. Higher values == thicker outline
r_celShadingThreshold		Set the cel shading threshold

r_useFilmgrain			Enable filmgrain postprocessing effect
r_filmgrainBlendMode		Set the grain blending mode. Value range: 0 - 3; 0 = gl_one, gl_one; 1 = gl_zero, gl_one_minus_src_color; 2 = gl_dst_color, gl_one; 3 = gl_one_minus_dst_color, gl_one
r_filmgrainScale		Set the grain scale
r_filmgrainStrength		Set the grain strength. Value range: 0.0 - 1.0

r_useVignetting			Enable vignetting postprocessing effect




//=================================================================================
// Acknowledgements:
//=================================================================================

id Software	- for Doom 3 and for everything else they have ever done since the beginning of time.

Trent Reznor	- for his amazing audio work that sadly was not used in the final game.

Deadite4	- for his awesome contribution of the sikkmod menu.

revility	- for his Demon Expansion Pak and allowing me to include it.

Maha_x		- for his Brilliant Highlights & Brilliant Bloom mods that got me started in Doom 3 shader programming.

6th Venom	- for his dof and ssao work which was both inspirational and showed me how to render depth.

Eutectic, et al - for the clean pak files which I used as a base for all included decl files.  

TRSGM		- for his original released work on chromatic dispersion, screen blood splats, and
        	  blood cubemaps.

jcdenton22	- for his HDR post @Doom3World.org (http://www.doom3world.org/phpbb2/viewtopic.php?f=56&t=23226)
	    	  which motivated me to take another look at the HDR stuff I had.

MAsta_KFC	- for his TRU ZOMBIE RESURRECT mod.

Unknown author	- for weapon sparks particle effects. I've had this mod on my pc since 2005 and 
	          no longer have the original zip or readme to give proper credit. I've tried 
	          searching for this mod but can't seem to find it. If anyone knows the source
		  for these particle effects, please let me know.


And a final thanks to BNA and all of Doom3World.org, the best community in gaming.

