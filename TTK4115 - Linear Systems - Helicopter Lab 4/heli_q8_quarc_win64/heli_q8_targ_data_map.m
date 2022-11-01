  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 8;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (heli_q8_P)
    ;%
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% heli_q8_P.A_L
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_P.B_L
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 25;
	
	  ;% heli_q8_P.C_L
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 35;
	
	  ;% heli_q8_P.F
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 60;
	
	  ;% heli_q8_P.Joystick_gain_x
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 64;
	
	  ;% heli_q8_P.Joystick_gain_y
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 65;
	
	  ;% heli_q8_P.K
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 66;
	
	  ;% heli_q8_P.L
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 76;
	
	  ;% heli_q8_P.V_s0
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 101;
	
	  ;% heli_q8_P.dev_rates_IMU
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 102;
	
	  ;% heli_q8_P.dev_states_IMU
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 105;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_P.HILWriteAnalog_channels
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 70;
      section.data(70)  = dumData; %prealloc
      
	  ;% heli_q8_P.HILInitialize_OOTerminate
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_P.HILInitialize_OOExit
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_P.HILInitialize_OOStart
	  section.data(3).logicalSrcIdx = 14;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_P.HILInitialize_OOEnter
	  section.data(4).logicalSrcIdx = 15;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_q8_P.HILInitialize_AOFinal
	  section.data(5).logicalSrcIdx = 16;
	  section.data(5).dtTransOffset = 4;
	
	  ;% heli_q8_P.HILInitialize_POFinal
	  section.data(6).logicalSrcIdx = 17;
	  section.data(6).dtTransOffset = 5;
	
	  ;% heli_q8_P.HILInitialize_AIHigh
	  section.data(7).logicalSrcIdx = 18;
	  section.data(7).dtTransOffset = 6;
	
	  ;% heli_q8_P.HILInitialize_AILow
	  section.data(8).logicalSrcIdx = 19;
	  section.data(8).dtTransOffset = 7;
	
	  ;% heli_q8_P.HILInitialize_AOHigh
	  section.data(9).logicalSrcIdx = 20;
	  section.data(9).dtTransOffset = 8;
	
	  ;% heli_q8_P.HILInitialize_AOLow
	  section.data(10).logicalSrcIdx = 21;
	  section.data(10).dtTransOffset = 9;
	
	  ;% heli_q8_P.HILInitialize_AOInitial
	  section.data(11).logicalSrcIdx = 22;
	  section.data(11).dtTransOffset = 10;
	
	  ;% heli_q8_P.HILInitialize_AOWatchdog
	  section.data(12).logicalSrcIdx = 23;
	  section.data(12).dtTransOffset = 11;
	
	  ;% heli_q8_P.HILInitialize_POFrequency
	  section.data(13).logicalSrcIdx = 24;
	  section.data(13).dtTransOffset = 12;
	
	  ;% heli_q8_P.HILInitialize_POLeading
	  section.data(14).logicalSrcIdx = 25;
	  section.data(14).dtTransOffset = 13;
	
	  ;% heli_q8_P.HILInitialize_POTrailing
	  section.data(15).logicalSrcIdx = 26;
	  section.data(15).dtTransOffset = 14;
	
	  ;% heli_q8_P.HILInitialize_POInitial
	  section.data(16).logicalSrcIdx = 27;
	  section.data(16).dtTransOffset = 15;
	
	  ;% heli_q8_P.HILInitialize_POWatchdog
	  section.data(17).logicalSrcIdx = 28;
	  section.data(17).dtTransOffset = 16;
	
	  ;% heli_q8_P.Constant_Value
	  section.data(18).logicalSrcIdx = 29;
	  section.data(18).dtTransOffset = 17;
	
	  ;% heli_q8_P.Constant1_Value
	  section.data(19).logicalSrcIdx = 30;
	  section.data(19).dtTransOffset = 18;
	
	  ;% heli_q8_P.Memory_InitialCondition
	  section.data(20).logicalSrcIdx = 31;
	  section.data(20).dtTransOffset = 19;
	
	  ;% heli_q8_P.Gain2_Gain
	  section.data(21).logicalSrcIdx = 32;
	  section.data(21).dtTransOffset = 29;
	
	  ;% heli_q8_P.ElevationCounttorad_Gain
	  section.data(22).logicalSrcIdx = 33;
	  section.data(22).dtTransOffset = 38;
	
	  ;% heli_q8_P.ElevationTransferFcn_A
	  section.data(23).logicalSrcIdx = 34;
	  section.data(23).dtTransOffset = 39;
	
	  ;% heli_q8_P.ElevationTransferFcn_C
	  section.data(24).logicalSrcIdx = 35;
	  section.data(24).dtTransOffset = 40;
	
	  ;% heli_q8_P.ElevationTransferFcn_D
	  section.data(25).logicalSrcIdx = 36;
	  section.data(25).dtTransOffset = 41;
	
	  ;% heli_q8_P.Integrator_IC
	  section.data(26).logicalSrcIdx = 37;
	  section.data(26).dtTransOffset = 42;
	
	  ;% heli_q8_P.Constant_Value_f
	  section.data(27).logicalSrcIdx = 38;
	  section.data(27).dtTransOffset = 43;
	
	  ;% heli_q8_P.Gain1_Gain
	  section.data(28).logicalSrcIdx = 39;
	  section.data(28).dtTransOffset = 44;
	
	  ;% heli_q8_P.PitchCounttorad_Gain
	  section.data(29).logicalSrcIdx = 40;
	  section.data(29).dtTransOffset = 53;
	
	  ;% heli_q8_P.PitchTransferFcn_A
	  section.data(30).logicalSrcIdx = 41;
	  section.data(30).dtTransOffset = 54;
	
	  ;% heli_q8_P.PitchTransferFcn_C
	  section.data(31).logicalSrcIdx = 42;
	  section.data(31).dtTransOffset = 55;
	
	  ;% heli_q8_P.PitchTransferFcn_D
	  section.data(32).logicalSrcIdx = 43;
	  section.data(32).dtTransOffset = 56;
	
	  ;% heli_q8_P.TravelCounttorad_Gain
	  section.data(33).logicalSrcIdx = 44;
	  section.data(33).dtTransOffset = 57;
	
	  ;% heli_q8_P.TravelTransferFcn_A
	  section.data(34).logicalSrcIdx = 45;
	  section.data(34).dtTransOffset = 58;
	
	  ;% heli_q8_P.TravelTransferFcn_C
	  section.data(35).logicalSrcIdx = 46;
	  section.data(35).dtTransOffset = 59;
	
	  ;% heli_q8_P.TravelTransferFcn_D
	  section.data(36).logicalSrcIdx = 47;
	  section.data(36).dtTransOffset = 60;
	
	  ;% heli_q8_P.Step1_Time
	  section.data(37).logicalSrcIdx = 48;
	  section.data(37).dtTransOffset = 61;
	
	  ;% heli_q8_P.Step1_Y0
	  section.data(38).logicalSrcIdx = 49;
	  section.data(38).dtTransOffset = 62;
	
	  ;% heli_q8_P.Step1_YFinal
	  section.data(39).logicalSrcIdx = 50;
	  section.data(39).dtTransOffset = 63;
	
	  ;% heli_q8_P.Step3_Time
	  section.data(40).logicalSrcIdx = 51;
	  section.data(40).dtTransOffset = 64;
	
	  ;% heli_q8_P.Step3_Y0
	  section.data(41).logicalSrcIdx = 52;
	  section.data(41).dtTransOffset = 65;
	
	  ;% heli_q8_P.Step3_YFinal
	  section.data(42).logicalSrcIdx = 53;
	  section.data(42).dtTransOffset = 66;
	
	  ;% heli_q8_P.Gain_Gain
	  section.data(43).logicalSrcIdx = 54;
	  section.data(43).dtTransOffset = 67;
	
	  ;% heli_q8_P.Step_Time
	  section.data(44).logicalSrcIdx = 55;
	  section.data(44).dtTransOffset = 68;
	
	  ;% heli_q8_P.Step_Y0
	  section.data(45).logicalSrcIdx = 56;
	  section.data(45).dtTransOffset = 69;
	
	  ;% heli_q8_P.Step_YFinal
	  section.data(46).logicalSrcIdx = 57;
	  section.data(46).dtTransOffset = 70;
	
	  ;% heli_q8_P.Step2_Time
	  section.data(47).logicalSrcIdx = 58;
	  section.data(47).dtTransOffset = 71;
	
	  ;% heli_q8_P.Step2_Y0
	  section.data(48).logicalSrcIdx = 59;
	  section.data(48).dtTransOffset = 72;
	
	  ;% heli_q8_P.Step2_YFinal
	  section.data(49).logicalSrcIdx = 60;
	  section.data(49).dtTransOffset = 73;
	
	  ;% heli_q8_P.Gain1_Gain_h
	  section.data(50).logicalSrcIdx = 61;
	  section.data(50).dtTransOffset = 74;
	
	  ;% heli_q8_P.Integrator_IC_f
	  section.data(51).logicalSrcIdx = 62;
	  section.data(51).dtTransOffset = 75;
	
	  ;% heli_q8_P.Integrator1_IC
	  section.data(52).logicalSrcIdx = 63;
	  section.data(52).dtTransOffset = 76;
	
	  ;% heli_q8_P.Backgain_Gain
	  section.data(53).logicalSrcIdx = 64;
	  section.data(53).dtTransOffset = 77;
	
	  ;% heli_q8_P.Frontgain_Gain
	  section.data(54).logicalSrcIdx = 65;
	  section.data(54).dtTransOffset = 78;
	
	  ;% heli_q8_P.FrontmotorSaturation_UpperSat
	  section.data(55).logicalSrcIdx = 66;
	  section.data(55).dtTransOffset = 79;
	
	  ;% heli_q8_P.FrontmotorSaturation_LowerSat
	  section.data(56).logicalSrcIdx = 67;
	  section.data(56).dtTransOffset = 80;
	
	  ;% heli_q8_P.BackmotorSaturation_UpperSat
	  section.data(57).logicalSrcIdx = 68;
	  section.data(57).dtTransOffset = 81;
	
	  ;% heli_q8_P.BackmotorSaturation_LowerSat
	  section.data(58).logicalSrcIdx = 69;
	  section.data(58).dtTransOffset = 82;
	
	  ;% heli_q8_P.Integrator_IC_k
	  section.data(59).logicalSrcIdx = 70;
	  section.data(59).dtTransOffset = 83;
	
	  ;% heli_q8_P.Integrator_UpperSat
	  section.data(60).logicalSrcIdx = 71;
	  section.data(60).dtTransOffset = 84;
	
	  ;% heli_q8_P.Integrator_LowerSat
	  section.data(61).logicalSrcIdx = 72;
	  section.data(61).dtTransOffset = 85;
	
	  ;% heli_q8_P.K_ei_Gain
	  section.data(62).logicalSrcIdx = 73;
	  section.data(62).dtTransOffset = 86;
	
	  ;% heli_q8_P.RateTransitionx_InitialConditio
	  section.data(63).logicalSrcIdx = 74;
	  section.data(63).dtTransOffset = 87;
	
	  ;% heli_q8_P.DeadZonex_Start
	  section.data(64).logicalSrcIdx = 75;
	  section.data(64).dtTransOffset = 88;
	
	  ;% heli_q8_P.DeadZonex_End
	  section.data(65).logicalSrcIdx = 76;
	  section.data(65).dtTransOffset = 89;
	
	  ;% heli_q8_P.Gainx_Gain
	  section.data(66).logicalSrcIdx = 77;
	  section.data(66).dtTransOffset = 90;
	
	  ;% heli_q8_P.RateTransitiony_InitialConditio
	  section.data(67).logicalSrcIdx = 78;
	  section.data(67).dtTransOffset = 91;
	
	  ;% heli_q8_P.DeadZoney_Start
	  section.data(68).logicalSrcIdx = 79;
	  section.data(68).dtTransOffset = 92;
	
	  ;% heli_q8_P.DeadZoney_End
	  section.data(69).logicalSrcIdx = 80;
	  section.data(69).dtTransOffset = 93;
	
	  ;% heli_q8_P.Gainy_Gain
	  section.data(70).logicalSrcIdx = 81;
	  section.data(70).dtTransOffset = 94;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% heli_q8_P.HILInitialize_CKChannels
	  section.data(1).logicalSrcIdx = 82;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_P.HILInitialize_DOWatchdog
	  section.data(2).logicalSrcIdx = 83;
	  section.data(2).dtTransOffset = 3;
	
	  ;% heli_q8_P.HILInitialize_EIInitial
	  section.data(3).logicalSrcIdx = 84;
	  section.data(3).dtTransOffset = 4;
	
	  ;% heli_q8_P.HILInitialize_POModes
	  section.data(4).logicalSrcIdx = 85;
	  section.data(4).dtTransOffset = 5;
	
	  ;% heli_q8_P.HILInitialize_POConfiguration
	  section.data(5).logicalSrcIdx = 86;
	  section.data(5).dtTransOffset = 6;
	
	  ;% heli_q8_P.HILInitialize_POAlignment
	  section.data(6).logicalSrcIdx = 87;
	  section.data(6).dtTransOffset = 7;
	
	  ;% heli_q8_P.HILInitialize_POPolarity
	  section.data(7).logicalSrcIdx = 88;
	  section.data(7).dtTransOffset = 8;
	
	  ;% heli_q8_P.HILReadEncoderTimebase_Clock
	  section.data(8).logicalSrcIdx = 89;
	  section.data(8).dtTransOffset = 9;
	
	  ;% heli_q8_P.StreamCall1_SendBufferSize
	  section.data(9).logicalSrcIdx = 90;
	  section.data(9).dtTransOffset = 10;
	
	  ;% heli_q8_P.StreamCall1_ReceiveBufferSize
	  section.data(10).logicalSrcIdx = 91;
	  section.data(10).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% heli_q8_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 92;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_P.HILInitialize_AOChannels
	  section.data(2).logicalSrcIdx = 93;
	  section.data(2).dtTransOffset = 8;
	
	  ;% heli_q8_P.HILInitialize_EIChannels
	  section.data(3).logicalSrcIdx = 94;
	  section.data(3).dtTransOffset = 16;
	
	  ;% heli_q8_P.HILInitialize_EIQuadrature
	  section.data(4).logicalSrcIdx = 95;
	  section.data(4).dtTransOffset = 24;
	
	  ;% heli_q8_P.HILInitialize_POChannels
	  section.data(5).logicalSrcIdx = 96;
	  section.data(5).dtTransOffset = 25;
	
	  ;% heli_q8_P.HILReadEncoderTimebase_Channels
	  section.data(6).logicalSrcIdx = 97;
	  section.data(6).dtTransOffset = 33;
	
	  ;% heli_q8_P.HILReadEncoderTimebase_SamplesI
	  section.data(7).logicalSrcIdx = 98;
	  section.data(7).dtTransOffset = 36;
	
	  ;% heli_q8_P.StreamFormattedWrite_MaxUnits
	  section.data(8).logicalSrcIdx = 99;
	  section.data(8).dtTransOffset = 37;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_P.GameController_BufferSize
	  section.data(1).logicalSrcIdx = 100;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 41;
      section.data(41)  = dumData; %prealloc
      
	  ;% heli_q8_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 101;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_P.HILInitialize_AOTerminate
	  section.data(2).logicalSrcIdx = 102;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_P.HILInitialize_AOExit
	  section.data(3).logicalSrcIdx = 103;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_P.HILInitialize_DOTerminate
	  section.data(4).logicalSrcIdx = 104;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_q8_P.HILInitialize_DOExit
	  section.data(5).logicalSrcIdx = 105;
	  section.data(5).dtTransOffset = 4;
	
	  ;% heli_q8_P.HILInitialize_POTerminate
	  section.data(6).logicalSrcIdx = 106;
	  section.data(6).dtTransOffset = 5;
	
	  ;% heli_q8_P.HILInitialize_POExit
	  section.data(7).logicalSrcIdx = 107;
	  section.data(7).dtTransOffset = 6;
	
	  ;% heli_q8_P.HILInitialize_CKPStart
	  section.data(8).logicalSrcIdx = 108;
	  section.data(8).dtTransOffset = 7;
	
	  ;% heli_q8_P.HILInitialize_CKPEnter
	  section.data(9).logicalSrcIdx = 109;
	  section.data(9).dtTransOffset = 8;
	
	  ;% heli_q8_P.HILInitialize_CKStart
	  section.data(10).logicalSrcIdx = 110;
	  section.data(10).dtTransOffset = 9;
	
	  ;% heli_q8_P.HILInitialize_CKEnter
	  section.data(11).logicalSrcIdx = 111;
	  section.data(11).dtTransOffset = 10;
	
	  ;% heli_q8_P.HILInitialize_AIPStart
	  section.data(12).logicalSrcIdx = 112;
	  section.data(12).dtTransOffset = 11;
	
	  ;% heli_q8_P.HILInitialize_AIPEnter
	  section.data(13).logicalSrcIdx = 113;
	  section.data(13).dtTransOffset = 12;
	
	  ;% heli_q8_P.HILInitialize_AOPStart
	  section.data(14).logicalSrcIdx = 114;
	  section.data(14).dtTransOffset = 13;
	
	  ;% heli_q8_P.HILInitialize_AOPEnter
	  section.data(15).logicalSrcIdx = 115;
	  section.data(15).dtTransOffset = 14;
	
	  ;% heli_q8_P.HILInitialize_AOStart
	  section.data(16).logicalSrcIdx = 116;
	  section.data(16).dtTransOffset = 15;
	
	  ;% heli_q8_P.HILInitialize_AOEnter
	  section.data(17).logicalSrcIdx = 117;
	  section.data(17).dtTransOffset = 16;
	
	  ;% heli_q8_P.HILInitialize_AOReset
	  section.data(18).logicalSrcIdx = 118;
	  section.data(18).dtTransOffset = 17;
	
	  ;% heli_q8_P.HILInitialize_DOPStart
	  section.data(19).logicalSrcIdx = 119;
	  section.data(19).dtTransOffset = 18;
	
	  ;% heli_q8_P.HILInitialize_DOPEnter
	  section.data(20).logicalSrcIdx = 120;
	  section.data(20).dtTransOffset = 19;
	
	  ;% heli_q8_P.HILInitialize_DOStart
	  section.data(21).logicalSrcIdx = 121;
	  section.data(21).dtTransOffset = 20;
	
	  ;% heli_q8_P.HILInitialize_DOEnter
	  section.data(22).logicalSrcIdx = 122;
	  section.data(22).dtTransOffset = 21;
	
	  ;% heli_q8_P.HILInitialize_DOReset
	  section.data(23).logicalSrcIdx = 123;
	  section.data(23).dtTransOffset = 22;
	
	  ;% heli_q8_P.HILInitialize_EIPStart
	  section.data(24).logicalSrcIdx = 124;
	  section.data(24).dtTransOffset = 23;
	
	  ;% heli_q8_P.HILInitialize_EIPEnter
	  section.data(25).logicalSrcIdx = 125;
	  section.data(25).dtTransOffset = 24;
	
	  ;% heli_q8_P.HILInitialize_EIStart
	  section.data(26).logicalSrcIdx = 126;
	  section.data(26).dtTransOffset = 25;
	
	  ;% heli_q8_P.HILInitialize_EIEnter
	  section.data(27).logicalSrcIdx = 127;
	  section.data(27).dtTransOffset = 26;
	
	  ;% heli_q8_P.HILInitialize_POPStart
	  section.data(28).logicalSrcIdx = 128;
	  section.data(28).dtTransOffset = 27;
	
	  ;% heli_q8_P.HILInitialize_POPEnter
	  section.data(29).logicalSrcIdx = 129;
	  section.data(29).dtTransOffset = 28;
	
	  ;% heli_q8_P.HILInitialize_POStart
	  section.data(30).logicalSrcIdx = 130;
	  section.data(30).dtTransOffset = 29;
	
	  ;% heli_q8_P.HILInitialize_POEnter
	  section.data(31).logicalSrcIdx = 131;
	  section.data(31).dtTransOffset = 30;
	
	  ;% heli_q8_P.HILInitialize_POReset
	  section.data(32).logicalSrcIdx = 132;
	  section.data(32).dtTransOffset = 31;
	
	  ;% heli_q8_P.HILInitialize_OOReset
	  section.data(33).logicalSrcIdx = 133;
	  section.data(33).dtTransOffset = 32;
	
	  ;% heli_q8_P.HILInitialize_DOFinal
	  section.data(34).logicalSrcIdx = 134;
	  section.data(34).dtTransOffset = 33;
	
	  ;% heli_q8_P.HILInitialize_DOInitial
	  section.data(35).logicalSrcIdx = 135;
	  section.data(35).dtTransOffset = 34;
	
	  ;% heli_q8_P.HILReadEncoderTimebase_Active
	  section.data(36).logicalSrcIdx = 136;
	  section.data(36).dtTransOffset = 35;
	
	  ;% heli_q8_P.StreamCall1_NonBlocking
	  section.data(37).logicalSrcIdx = 137;
	  section.data(37).dtTransOffset = 36;
	
	  ;% heli_q8_P.StreamCall1_Active
	  section.data(38).logicalSrcIdx = 138;
	  section.data(38).dtTransOffset = 37;
	
	  ;% heli_q8_P.HILWriteAnalog_Active
	  section.data(39).logicalSrcIdx = 139;
	  section.data(39).dtTransOffset = 38;
	
	  ;% heli_q8_P.GameController_AutoCenter
	  section.data(40).logicalSrcIdx = 140;
	  section.data(40).dtTransOffset = 39;
	
	  ;% heli_q8_P.GameController_Enabled
	  section.data(41).logicalSrcIdx = 141;
	  section.data(41).dtTransOffset = 40;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% heli_q8_P.HILReadEncoderTimebase_Overflow
	  section.data(1).logicalSrcIdx = 142;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_P.StringConstant_Value
	  section.data(2).logicalSrcIdx = 143;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_P.StreamCall1_URI
	  section.data(3).logicalSrcIdx = 144;
	  section.data(3).dtTransOffset = 256;
	
	  ;% heli_q8_P.StreamCall1_Endian
	  section.data(4).logicalSrcIdx = 145;
	  section.data(4).dtTransOffset = 257;
	
	  ;% heli_q8_P.GameController_ControllerNumber
	  section.data(5).logicalSrcIdx = 146;
	  section.data(5).dtTransOffset = 258;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (heli_q8_B)
    ;%
      section.nData     = 24;
      section.data(24)  = dumData; %prealloc
      
	  ;% heli_q8_B.Switch
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_B.Gain2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 10;
	
	  ;% heli_q8_B.ElevationCounttorad
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 13;
	
	  ;% heli_q8_B.ElevationTransferFcn
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 14;
	
	  ;% heli_q8_B.Integrator
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 15;
	
	  ;% heli_q8_B.Sum
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 20;
	
	  ;% heli_q8_B.Sum1
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 21;
	
	  ;% heli_q8_B.Sum3
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 23;
	
	  ;% heli_q8_B.PitchCounttorad
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 26;
	
	  ;% heli_q8_B.PitchTransferFcn
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 27;
	
	  ;% heli_q8_B.TravelCounttorad
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 28;
	
	  ;% heli_q8_B.TravelTransferFcn
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 29;
	
	  ;% heli_q8_B.Gain
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 30;
	
	  ;% heli_q8_B.Gain1
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 31;
	
	  ;% heli_q8_B.FrontmotorSaturation
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 32;
	
	  ;% heli_q8_B.BackmotorSaturation
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 33;
	
	  ;% heli_q8_B.Sum7
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 34;
	
	  ;% heli_q8_B.Sum8
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 35;
	
	  ;% heli_q8_B.Sum1_c
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 36;
	
	  ;% heli_q8_B.K_ei
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 41;
	
	  ;% heli_q8_B.RateTransitionx
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 42;
	
	  ;% heli_q8_B.Joystick_gain_x
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 43;
	
	  ;% heli_q8_B.RateTransitiony
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 44;
	
	  ;% heli_q8_B.Joystick_gain_y
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 45;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_B.StreamCall1_o2
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 10;
    sectIdxOffset = 2;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (heli_q8_DW)
    ;%
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% heli_q8_DW.HILInitialize_AIMinimums
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_DW.HILInitialize_AIMaximums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 8;
	
	  ;% heli_q8_DW.HILInitialize_AOMinimums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 16;
	
	  ;% heli_q8_DW.HILInitialize_AOMaximums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 24;
	
	  ;% heli_q8_DW.HILInitialize_AOVoltages
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 32;
	
	  ;% heli_q8_DW.HILInitialize_FilterFrequency
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 40;
	
	  ;% heli_q8_DW.HILInitialize_POSortedFreqs
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 48;
	
	  ;% heli_q8_DW.HILInitialize_POValues
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 56;
	
	  ;% heli_q8_DW.Memory_PreviousInput
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 64;
	
	  ;% heli_q8_DW.HILWriteAnalog_Buffer
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 74;
	
	  ;% heli_q8_DW.RateTransitionx_Buffer0
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 76;
	
	  ;% heli_q8_DW.RateTransitiony_Buffer0
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 77;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_DW.StreamCall1_Stream
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_DW.GameController_Controller
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_DW.HILReadEncoderTimebase_Task
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 24;
      section.data(24)  = dumData; %prealloc
      
	  ;% heli_q8_DW.Accelerometer_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_DW.Elevratevsest_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 3;
	
	  ;% heli_q8_DW.Elevvsest_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 18;
	  section.data(3).dtTransOffset = 5;
	
	  ;% heli_q8_DW.Elevation_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 19;
	  section.data(4).dtTransOffset = 7;
	
	  ;% heli_q8_DW.Elevationrate_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 20;
	  section.data(5).dtTransOffset = 9;
	
	  ;% heli_q8_DW.Pitch_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 21;
	  section.data(6).dtTransOffset = 11;
	
	  ;% heli_q8_DW.Pitchrate_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 22;
	  section.data(7).dtTransOffset = 13;
	
	  ;% heli_q8_DW.Pitchratevsest_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 23;
	  section.data(8).dtTransOffset = 15;
	
	  ;% heli_q8_DW.Pitchvsest_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 24;
	  section.data(9).dtTransOffset = 17;
	
	  ;% heli_q8_DW.ToFile_PWORK.FilePtr
	  section.data(10).logicalSrcIdx = 25;
	  section.data(10).dtTransOffset = 19;
	
	  ;% heli_q8_DW.ToFile1_PWORK.FilePtr
	  section.data(11).logicalSrcIdx = 26;
	  section.data(11).dtTransOffset = 20;
	
	  ;% heli_q8_DW.Travel_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 27;
	  section.data(12).dtTransOffset = 21;
	
	  ;% heli_q8_DW.Travelrate_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 28;
	  section.data(13).dtTransOffset = 23;
	
	  ;% heli_q8_DW.Travelratevsest_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 29;
	  section.data(14).dtTransOffset = 25;
	
	  ;% heli_q8_DW.ElevationScoperads_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 30;
	  section.data(15).dtTransOffset = 27;
	
	  ;% heli_q8_DW.ElevationScoperad_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 31;
	  section.data(16).dtTransOffset = 28;
	
	  ;% heli_q8_DW.PitchScoperad_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 32;
	  section.data(17).dtTransOffset = 29;
	
	  ;% heli_q8_DW.PtichrateScoperads_PWORK.LoggedData
	  section.data(18).logicalSrcIdx = 33;
	  section.data(18).dtTransOffset = 30;
	
	  ;% heli_q8_DW.TravelrateScoperads_PWORK.LoggedData
	  section.data(19).logicalSrcIdx = 34;
	  section.data(19).dtTransOffset = 31;
	
	  ;% heli_q8_DW.TravelScoperad_PWORK.LoggedData
	  section.data(20).logicalSrcIdx = 35;
	  section.data(20).dtTransOffset = 32;
	
	  ;% heli_q8_DW.HILWriteAnalog_PWORK
	  section.data(21).logicalSrcIdx = 36;
	  section.data(21).dtTransOffset = 33;
	
	  ;% heli_q8_DW.Connected_PWORK.LoggedData
	  section.data(22).logicalSrcIdx = 37;
	  section.data(22).dtTransOffset = 34;
	
	  ;% heli_q8_DW.XScope_PWORK.LoggedData
	  section.data(23).logicalSrcIdx = 38;
	  section.data(23).dtTransOffset = 35;
	
	  ;% heli_q8_DW.YScope_PWORK.LoggedData
	  section.data(24).logicalSrcIdx = 39;
	  section.data(24).dtTransOffset = 36;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% heli_q8_DW.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_DW.HILInitialize_QuadratureModes
	  section.data(2).logicalSrcIdx = 41;
	  section.data(2).dtTransOffset = 3;
	
	  ;% heli_q8_DW.HILInitialize_InitialEICounts
	  section.data(3).logicalSrcIdx = 42;
	  section.data(3).dtTransOffset = 11;
	
	  ;% heli_q8_DW.HILInitialize_POModeValues
	  section.data(4).logicalSrcIdx = 43;
	  section.data(4).dtTransOffset = 19;
	
	  ;% heli_q8_DW.HILInitialize_POAlignValues
	  section.data(5).logicalSrcIdx = 44;
	  section.data(5).dtTransOffset = 27;
	
	  ;% heli_q8_DW.HILInitialize_POPolarityVals
	  section.data(6).logicalSrcIdx = 45;
	  section.data(6).dtTransOffset = 35;
	
	  ;% heli_q8_DW.HILReadEncoderTimebase_Buffer
	  section.data(7).logicalSrcIdx = 46;
	  section.data(7).dtTransOffset = 43;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_DW.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 47;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% heli_q8_DW.ToFile_IWORK.Count
	  section.data(1).logicalSrcIdx = 48;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_DW.ToFile1_IWORK.Count
	  section.data(2).logicalSrcIdx = 49;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_DW.StreamCall1_State
	  section.data(1).logicalSrcIdx = 50;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 570426339;
  targMap.checksum1 = 3270585581;
  targMap.checksum2 = 2488248068;
  targMap.checksum3 = 2348474271;

