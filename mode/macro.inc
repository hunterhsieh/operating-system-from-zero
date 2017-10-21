;Fill the Descriptor Table
;	%macro [macroName] [numberOfParameters]
;	%endmacro
;WAY TO USE
;LABEL:	Descriptor	Base, Limit,	Attribute

%macro Descriptor 3
	dw %2 & 0FFFFh
	dw %1 & 0FFFFh
	db (%1>>16) & 0FFh
	dw ((%2>>8) & 0F00h) | (%3 & 0F0FFh)
	db (%1>>24) & 0FFh
%endmacro

;Descriptor attribute
;----------------------------------------------------------------------------
; Type definitions
;       DA_  : Descriptor Attribute
;		G	 : Granularity
;       D    : Data Segment
;       C    : Code Segment
;       S    : System Segment
;       R    : Read
;       RW   : Read & write
;       A    : Access
;----------------------------------------------------------------------------
DA_16		EQU 0000h
DA_32		EQU	4000h	; 32 ��q

DA_G_1B		EQU	0000h	; Limit����쬰1B
DA_G_4KB	EQU	8000h	; Limit����쬰4KB

DA_DPL0		EQU	  00h	; DPL = 0
DA_DPL1		EQU	  20h	; DPL = 1
DA_DPL2		EQU	  40h	; DPL = 2
DA_DPL3		EQU	  60h	; DPL = 3
;----------------------------------------------------------------------------
; �s�x�q�y�z�������Ȼ���
;----------------------------------------------------------------------------
DA_DR		EQU	90h	; �s�b���uŪ�ƾڬq������
DA_DRW		EQU	92h	; �s�b���iŪ�g�ƾڬq�ݩʭ�
DA_DRWA		EQU	93h	; �s�b���w�X�ݥiŪ�g�ƾڬq������
DA_C		EQU	98h	; �s�b���u����N�X�q�ݩʭ�
DA_CR		EQU	9Ah	; �s�b���i����iŪ�N�X�q�ݩʭ�
DA_CCO		EQU	9Ch	; �s�b���u����@�P�N�X�q�ݩʭ�
DA_CCOR		EQU	9Eh	; �s�b���i����iŪ�@�P�N�X�q�ݩʭ�