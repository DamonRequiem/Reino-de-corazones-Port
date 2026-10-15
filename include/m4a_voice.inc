	.macro _voice_pan pan:req
	.if \pan
	.byte 0x80 | \pan
	.else
	.byte 0
	.endif
	.endm

	.macro _voice_pointer type:req, key:req, pan:req, pointer:req, attack:req, decay:req, sustain:req, release:req
	.byte \type, \key, 0
	_voice_pan \pan
	.4byte \pointer
	.byte \attack, \decay, \sustain, \release
	.endm

	.macro voice_directsound key:req, pan:req, sample:req, attack:req, decay:req, sustain:req, release:req
	_voice_pointer 0x00, \key, \pan, \sample, \attack, \decay, \sustain, \release
	.endm

	.macro voice_directsound_no_resample key:req, pan:req, sample:req, attack:req, decay:req, sustain:req, release:req
	_voice_pointer 0x08, \key, \pan, \sample, \attack, \decay, \sustain, \release
	.endm

	.macro voice_directsound_alt key:req, pan:req, sample:req, attack:req, decay:req, sustain:req, release:req
	_voice_pointer 0x10, \key, \pan, \sample, \attack, \decay, \sustain, \release
	.endm

	.macro _voice_square_1 type:req, key:req, pan:req, sweep:req, duty_cycle:req, attack:req, decay:req, sustain:req, release:req
	.byte \type, \key, 0
	_voice_pan \pan
	.byte \sweep, \duty_cycle, 0, 0
	.byte \attack, \decay, \sustain, \release
	.endm

	.macro voice_square_1 key:req, pan:req, sweep:req, duty_cycle:req, attack:req, decay:req, sustain:req, release:req
	_voice_square_1 0x01, \key, \pan, \sweep, \duty_cycle, \attack, \decay, \sustain, \release
	.endm

	.macro voice_square_1_alt key:req, pan:req, sweep:req, duty_cycle:req, attack:req, decay:req, sustain:req, release:req
	_voice_square_1 0x09, \key, \pan, \sweep, \duty_cycle, \attack, \decay, \sustain, \release
	.endm

	.macro _voice_cgb type:req, key:req, pan:req, setting:req, attack:req, decay:req, sustain:req, release:req
	.byte \type, \key, 0
	_voice_pan \pan
	.byte \setting, 0, 0, 0
	.byte \attack, \decay, \sustain, \release
	.endm

	.macro voice_square_2 key:req, pan:req, duty_cycle:req, attack:req, decay:req, sustain:req, release:req
	_voice_cgb 0x02, \key, \pan, \duty_cycle, \attack, \decay, \sustain, \release
	.endm

	.macro voice_square_2_alt key:req, pan:req, duty_cycle:req, attack:req, decay:req, sustain:req, release:req
	_voice_cgb 0x0a, \key, \pan, \duty_cycle, \attack, \decay, \sustain, \release
	.endm

	.macro voice_noise key:req, pan:req, period:req, attack:req, decay:req, sustain:req, release:req
	_voice_cgb 0x04, \key, \pan, \period, \attack, \decay, \sustain, \release
	.endm

	.macro voice_noise_alt key:req, pan:req, period:req, attack:req, decay:req, sustain:req, release:req
	_voice_cgb 0x0c, \key, \pan, \period, \attack, \decay, \sustain, \release
	.endm

	.macro voice_programmable_wave key:req, pan:req, wave:req, attack:req, decay:req, sustain:req, release:req
	_voice_pointer 0x03, \key, \pan, \wave, \attack, \decay, \sustain, \release
	.endm

	.macro voice_programmable_wave_alt key:req, pan:req, wave:req, attack:req, decay:req, sustain:req, release:req
	_voice_pointer 0x0b, \key, \pan, \wave, \attack, \decay, \sustain, \release
	.endm

	.macro voice_keysplit group:req, table:req
	.byte 0x40, 0, 0, 0
	.4byte \group
	.4byte \table
	.endm

	.macro voice_keysplit_all group:req, first_note=0
	.byte 0x80, 0, 0, 0
	.4byte \group - \first_note * 12
	.4byte 0
	.endm

	.macro keysplit name:req, first_note:req
	.global \name
	.set \name, . - \first_note
	.set _keysplit_note, \first_note
	.endm

	.macro split voice:req, end_note:req
	.fill \end_note - _keysplit_note, 1, \voice
	.set _keysplit_note, \end_note
	.endm
