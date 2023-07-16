#ifndef Common_Macros
#define Common_Macros

#define SET_BIT(REG,BIT)    (REG |= (1<<BIT))
#define CLEAR_BIT(REG,BIT)  (REG &= ~(1<<BIT))
#define GET_BIT(REG,BIT)    (((REG) >> (BIT)) & 0x01)


#endif
