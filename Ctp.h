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
