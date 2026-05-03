typedef struct CtpSnmpInfo{
    char        TrapAble;           // Traps are possible (setup is good)
    char        TrapComm[32];       // TrapCommunity
    char        TrapHost[CTP_MAX_TRAP_HOSTS][60];      // Trap dest hosts
    char        TrapOid[32];        // Trap enterprise base OID
// Aricent PR 1362733 fix - Start
    char        TrapEngine[500];    // TrapEngine
    char        TrapUser[CTP_MAX_TRAP_HOSTS][60];     // TrapUser
    char        TrapPass[CTP_MAX_TRAP_HOSTS][60];     // TrapPwd
    char        TrapType;           // v2 or v3 trap
// Aricent PR 1362733 fix - End
} CTP_SNMP_INFO ;


[root@ctp_141:/home/ctp_cmd 1]# sb

>>>>> Circuit Emulation Bundles <<<<<
Bndl BndlTyp    Port      TS         RemAddr     CID    LCID RunState RCtr
==========================================================================
   0     CTP  te-0/0     N/A  10.216.118.141       0       0  RUNNING    1
==========================================================================
Checked out PPS - All Bundles: 188, System Maximum: 12500
   (1 PPS = full duplex packet transfer, Bundle <---> IP network)
[root@ctp_141:/home/ctp_cmd 2]# scenario.pl -b disable
Error.
[root@ctp_141:/home/ctp_cmd 3]# t
Sun May  3 19:30:50 2026 ctp_141 snmptrap: Trap: Sent node trap /usr/bin/snmptrap -e 0x80001f8804443939496b4b7a745272 -v 3 -u user1 -l authPriv -a SHA -A user1password -x AES -X user1password2 10.216.118.96 '' 1.3.6.1.4.1.18841.1.2.1.6.0.19 1.3.6.1.4.1.18841.1.2.1.5.19 s "Bundle 0 status changed to Activate"
May  3 19:30:51 ctp_141 ctpd: 7 ctp_timer_proc_t1card: te-0/0  T1/E1 LOS state changed to 1#012
May  3 19:30:55 ctp_141 ctpd: 7      util_prt_psc: te-0/0  B0 St Chg: EVAL to NoSYNC
May  3 19:30:58 ctp_141 ctpd: 7      util_prt_psc: te-0/0  B0 St Chg: NoSYNC to InSYNC
May  3 19:30:59 ctp_141 ctpd: 7      util_prt_psc: te-0/0  B0 St Chg: InSYNC to RUNNING
May  3 19:32:28 ctp_141 kernel:device eth4 left promiscuous mode
May  3 19:32:30 ctp_141 kernel:device eth4 entered promiscuous mode
May  3 19:44:42 ctp_141 ctpd: 7      util_prt_psc: te-0/0  B0 St Chg: RUNNING to DISABLD
Sun May  3 19:44:42 2026 ctp_141 snmptrap: Trap: Sent node trap /usr/bin/snmptrap -e 0x80001f8804443939496b4b7a745272 -v 3 -u user1 -l authPriv -a SHA -A user1password -x AES -X user1password2 10.0.0.0 '' 1.3.6.1.4.1.18841.1.2.1.6.0.17 1.3.6.1.4.1.18841.1.2.1.5.17 s "Bundle 0 status changed to Disable"
Sun May  3 19:44:42 2026 ctp_141 snmptrap: Trap: Sent node trap /usr/bin/snmptrap -e 0x80001f8804443939496b4b7a745272 -v 3 -u user1 -l authPriv -a SHA -A user1password -x AES -X user1password2 10.216.118.96 '' 1.3.6.1.4.1.18841.1.2.1.6.0.17 1.3.6.1.4.1.18841.1.2.1.5.17 s "Bundle 0 status changed to Disable"


[root@ctp_141:/home/ctp_cmd 3]# tcpdump -i eth4 | grep snmp
tcpdump: verbose output suppressed, use -v[v]... for full protocol decode
listening on eth4, link-type EN10MB (Ethernet), snapshot length 262144 bytes
19:44:42.833526 IP ctp_141.45453 > 10.0.0.0.snmp-trap:  F=ap U="user1" [!scoped PDU]1f_b0_f5_29_9f_c7_10_72_91_e9_cf_52_87_17_0b_25_b6_4d_83_89_93_1a_5b_8e_01_40_8c_b5_dd_01_6c_0c_18_58_00_ed_e9_25_7d_b4_f3_b3_e2_55_30_92_08_70_f7_39_ca_d4_f2_60_de_04_1a_1e_39_cf_8d_b2_8a_fc_63_b4_26_78_65_e2_d9_92_09_69_f1_cb_ad_17_80_f7_c1_a9_be_9e_e0_00_c8_d7_36_07_01_9c_ba_9b_52_28_43_52_4d_74_a8_ef_9b_53_f3_a9_53_0d_1d_c3_33_bc_8a_34_52_0d_32_6d_ea_19_93_31_c6_ee_fc_02_8d_18_7c_39_ba_df_28_5c_5c_28_5c_83_2f_72
19:44:42.942195 IP ctp_141.35514 > 10.216.118.96.snmp-trap:  F=ap U="user1" [!scoped PDU]1a_df_36_0d_70_8a_de_d9_5b_9c_8a_29_24_ee_a9_d3_3d_90_a6_ef_e1_98_ad_8a_5b_4c_89_f5_36_29_b6_20_33_e9_ad_34_01_43_41_a2_85_74_7c_98_3d_0b_2e_f2_44_6f_43_9e_eb_6c_e1_eb_21_e9_ae_ae_6e_8f_79_20_99_4a_57_86_f2_85_25_c9_1c_16_a3_19_ad_04_83_e9_87_32_cf_cd_a7_74_8d_47_3e_6c_ec_99_f4_f0_0a_c6_fc_7a_44_c1_6d_35_7d_c3_cb_95_c4_f4_b2_e6_23_86_f6_84_36_b0_46_31_87_e8_fd_4e_b0_2c_af_0c_34_59_65_17_49_2c_15_55_72_b6_a9_ff_97_87
19:44:44.397699 IP ctp_141.49032 > 10.0.0.0.snmp-trap:  F= U="user1" E=_80_00_1f_88_80_1f_da_93_32_aa_7f_f7_69_00_00_00_00 C="" V2Trap(141)  system.sysUpTime.0=1015785 S:1.1.4.1.0=E:18841.1.2.1.6.0.11 E:18841.1.2.1.5.11="LOS  00 00 00 00 00 00 00 LOF 00 00 00 00 00 00 00  BD:, PD: "
19:44:44.496224 IP ctp_141.51443 > 10.216.118.96.snmp-trap:  F= U="user1" E=_80_00_1f_88_80_1f_da_93_32_aa_7f_f7_69_00_00_00_00 C="" V2Trap(141)  system.sysUpTime.0=1015795 S:1.1.4.1.0=E:18841.1.2.1.6.0.11 E:18841.1.2.1.5.11="LOS  00 00 00 00 00 00 00 LOF 00 00 00 00 00 00 00  BD:, PD: "


The Solution: Update ctp_trans_trap in ctpd.c
Locate the ctp_trans_trap function (found around line 23908) and replace the entire function with the code below.

    //-------------------------------------------------------------------------
// This function sends a trap
//-------------------------------------------------------------------------
int ctp_trans_trap(void)
{
  int i, j, status = SUCCESS;
  FILE *fp;
  FUNC_PRT(ctp_trans_trap, PF_TRAP, 0);

  if( snmpTrapBufPtrTail != snmpTrapBufPtrHead ) {
    snmpTrapBufPtrTail++;
    snmpTrapBufPtrTail %= SNMP_TRAP_BUF_RING_SIZE;
    PRTDV(GEN,Processing snmpTrapBufPtrTail,snmpTrapBufPtrTail);

    for(i=0;i<CTP_MAX_TRAP_HOSTS;i++) {
      if( strcmp(Ctp.Snmp.TrapHost[i],"none") != 0 ) {
        
        // --- Logic Change: Only send v2c if v3 is NOT configured ---
        // This prevents the redundant v2c traps you saw in tcpdump
        if ((is_v2 != 0) && (Ctp.Snmp.TrapType != 3)) {
#ifdef WRL
          sprintf( snmpTrapCmdBuf,
              "/usr/bin/snmptrap -v 2c -c %s %s \'\' %s",
              Ctp.Snmp.TrapComm,
              Ctp.Snmp.TrapHost[i],
              &snmpTrapBuf[snmpTrapBufPtrTail][0]);
#else
          sprintf( snmpTrapCmdBuf, 
              "/usr/local/bin/snmptrap -v 2c -c %s %s \'\' %s",
              Ctp.Snmp.TrapComm, 
              Ctp.Snmp.TrapHost[i], 
              &snmpTrapBuf[snmpTrapBufPtrTail][0]);
#endif
          PRTS(EVE,Sent node trap (v2c), snmpTrapCmdBuf);
#ifdef WRL
          fp = popen(snmpTrapCmdBuf, "r");
          if(!fp){
            PRTS(EVE, Could not open pipe for output, snmpTrapCmdBuf);
            status = FAILURE;
          } else { pclose(fp); }
#else
          if( acorn_system(snmpTrapCmdBuf) ) { status = FAILURE; }
#endif
        }

        // --- UPDATED SNMPv3 LOGIC (Encrypted) ---
        if (Ctp.Snmp.TrapType == 3) {
           for(j=0;j<CTP_MAX_TRAP_HOSTS;j++) {
              if( strcmp(Ctp.Snmp.TrapUser[j],"none") != 0 ) {
#ifdef WRL
                  // UPDATED: Added -l authPriv and -X flag with TrapPrivPass[j]
                  sprintf( snmpTrapCmdBuf,
                      "/usr/bin/snmptrap -e %s -v 3 -u %s -l authPriv -a SHA -A \"%s\" -x AES -X \"%s\" %s \'\' %s",
                      Ctp.Snmp.TrapEngine, Ctp.Snmp.TrapUser[j],
                      Ctp.Snmp.TrapPass[j], Ctp.Snmp.TrapPrivPass[j], Ctp.Snmp.TrapHost[i],
                      &snmpTrapBuf[snmpTrapBufPtrTail][0]);
                  PRTS(EVE,Sent node trap (v3-Encrypted), snmpTrapCmdBuf);

                  fp = popen(snmpTrapCmdBuf, "r");
                  if(!fp){
                    PRTS(EVE, Could not open pipe for output, snmpTrapCmdBuf);
                    status = FAILURE;
                  } else { pclose(fp); }
#else
                  sprintf( snmpTrapCmdBuf,
                      "/usr/local/bin/snmptrap -e %s -v 3 -u %s -l authPriv -a SHA -A \"%s\" -x AES -X \"%s\" %s \'\' %s",
                      Ctp.Snmp.TrapEngine, Ctp.Snmp.TrapUser[j],
                      Ctp.Snmp.TrapPass[j], Ctp.Snmp.TrapPrivPass[j], Ctp.Snmp.TrapHost[i],
                      &snmpTrapBuf[snmpTrapBufPtrTail][0]);
                  PRTS(EVE,Sent node trap (v3-Encrypted), snmpTrapCmdBuf);

                  if( acorn_system(snmpTrapCmdBuf) ) {
                    PRT(MAJ,send_trap: system call failed.);
                    status = FAILURE;
                  }
#endif
              }
           }
        }
      } else { break; } // hit a "none", so stop
    }
    memset(&snmpTrapBuf[snmpTrapBufPtrTail][0], 0, SNMP_TRAP_BUF_SIZE);
  }
  return status;
}

    
