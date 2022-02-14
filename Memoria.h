
#ifndef Memoria_H
#define Memoria_H

#define INPUT	1
#define OUTPUT	0


#define MemorySECTOR			512
#define MemoryPAGE				528
#define MemoryBLOCK_SECTORS		32
#define MemoryBLOCK_SIZE		MemorySECTOR * MemoryBLOCK_SECTORS
#define MemoryTOTAL_SECTOR		0x8000
#define MemoryTOTAL_BLOCKS		MemoryTOTAL_SECTOR/MemoryBLOCK_SECTORS

/********************************************************
Estado da porta 8000h
*********************************************************/
								/*   ______ WR  */
								/*  | _____ RD  */
								/*  || ____ ALE */
								/*  ||| ___ CLE */
								/*  ||||  _ CS  */
								/*  |||| |      */
#define	MemoryIDLE		0x30	/*00110001b	RE e WE em 1, ALE e CLE em 0 */
#define	MemorySELECT	0x30	/*00110000b */
#define	MemorySET_CMD	0x34	/*00110100b */
#define	MemoryWR_CMD	0x14	/*00010100b */
#define	MemorySET_ALE	0x38	/*00111000b */
#define	MemoryWR_ALE	0x18	/*00011000b */
#define	MemoryBUFIN		0x30	/*00110000b */
#define	MemoryRD_DATA	0x20	/*00100000b */
#define	MemoryWR_DATA	0x10	/*00010000b */

/********************************************************
Comandos da Memoria
*********************************************************/
#define MemoryREAD_A					0x00
#define MemoryREAD_B					0x01
#define MemoryREAD_C					0x50
#define MemoryREAD_ID					0x90
#define MemoryREAD_STATUS				0x70
#define MemoryPROGRAM					0x10
#define MemoryDATA_IN					0x80
#define MemorySET_BLOCK_ERASE			0x60
#define MemoryBLOCK_ERASE				0xD0
#define MemoryCOPY_BACK					0x8A
#define MemoryRESET						0xFF

#endif
