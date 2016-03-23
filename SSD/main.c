/*
 #inc * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */
#include "types.h"
#include "SSD_interface.h"
#include "DIO_interface.h"
#include "DELAY.h"
#define rows 6
#define cols 16
#define iterat 8
#define phaseIterate 7
#define Arows 11
#define Brows 8
#define Acols 16

u8 Local_u8ValueArr[4] = { 0, 1, 2, 3 };
u8 Local_u8BtnVal,
Local_u8BounceFlag = 0;
//u8 temp[5][8]={0};
void main(void) {

	SSD_voidInit();


	while (1) {

	/*	DIO_u8ReadPinVal(DIO_u8PIN4, &Local_u8BtnVal);

		if (Local_u8BtnVal == DIO_u8HIGH && Local_u8BounceFlag == 0) {
			Local_u8BounceFlag = 1;
			//delay_ms(10);
			++Local_u8ValueArr[0];
			if (Local_u8ValueArr[0] > 9) {
				Local_u8ValueArr[0] = 0;
				++Local_u8ValueArr[1];

				if (Local_u8ValueArr[1] > 9) {
					Local_u8ValueArr[1] = 0;
					++Local_u8ValueArr[2];

					if (Local_u8ValueArr[2] > 9) {
						Local_u8ValueArr[2] = 0;
						++Local_u8ValueArr[3];

						if (Local_u8ValueArr[3] > 9) {
							Local_u8ValueArr[3] = 0;
						}
					}

				}
			}

		} else if (Local_u8BtnVal == DIO_u8LOW && Local_u8BounceFlag == 1) {
			Local_u8BounceFlag = 0;
		} else {

		}*/
	/*	SSD_u8TurnOff(SSD_u8DISP1);
		SSD_u8TurnOff(SSD_u8DISP2);
		SSD_u8TurnOff(SSD_u8DISP3);
		SSD_u8TurnOff(SSD_u8DISP4);

		SSD_u8Display(SSD_u8DISP1, Local_u8ValueArr[0]);
		SSD_u8TurnOn(SSD_u8DISP1);
		delay_ms(5);
		//_voidLetterB();
		SSD_u8TurnOff(SSD_u8DISP1);

		SSD_u8Display(SSD_u8DISP3, Local_u8ValueArr[1]);
		SSD_u8TurnOn(SSD_u8DISP2);
		delay_ms(5);
		//_voidLetterL();
		SSD_u8TurnOff(SSD_u8DISP2);

		SSD_u8Display(SSD_u8DISP3, Local_u8ValueArr[2]);
		SSD_u8TurnOn(SSD_u8DISP3);
		delay_ms(5);
		//_voidLetterA();
		SSD_u8TurnOff(SSD_u8DISP3);

		SSD_u8Display(SSD_u8DISP4, Local_u8ValueArr[3]);
		SSD_u8TurnOn(SSD_u8DISP4);
		delay_ms(5);
		//_voidLetterL();
		SSD_u8TurnOff(SSD_u8DISP4);*/

	//	DIO_u8WritePinVal(29, 0);
	//	DIO_u8WritePinVal(31, 1);

		_voidLetterB();
	//	delay_ms(150);
		_voidLetterE();
	//	delay_ms(150);
		_voidLetterL();
	//	delay_ms(150);
		_voidLetterA();
	//	delay_ms(150);
	    _voidLetterL();
	 //   delay_ms(150);
	//	DIO_u8WritePinVal(18, 1);


	}

	return;
}

void _voidLetterB(void) {

	u8 B[Brows][cols] =  {
							 { 0, 0, 0, 0, 0, 0, 0, 0,    1, 0, 0, 0, 0, 0, 0, 0 },
				             { 0, 1, 1, 1, 0, 1, 1, 0,    0, 1, 0, 0, 0, 0, 0, 0 },
			        	     { 0, 1, 1, 1, 0, 1, 1, 0,    0, 0, 1, 0, 0, 0, 0, 0 },
					         { 0, 1, 1, 1, 0, 1, 1, 0,    0, 0, 0, 1, 0, 0, 0, 0 },
					         { 1, 0, 0, 0, 1, 0, 0, 1,    0, 0, 0, 0, 1, 0, 0, 0 }
							 };

	/*u8 B[Brows][cols] =  {
			                         { 	1, 0, 0, 0, 0, 0, 0, 0	, 				0, 0, 0, 0, 0, 0, 0, 0   },
		                        	 { 	0, 1, 0, 0, 0, 0, 0, 0	, 	            0, 1, 1, 1, 0, 1, 1, 0   },
		                        	 { 	0, 0, 1, 0, 0, 0, 0, 0	,         	    0, 1, 1, 1, 0, 1, 1, 0   },
		                        	 { 	0, 0, 0, 1, 0, 0, 0, 0	, 		        0, 1, 1, 1, 0, 1, 1, 0   },
			                         { 	0, 0, 0, 0, 1, 0, 0, 0	, 		        1, 0, 0, 0, 1, 0, 0, 1   },
		                          	 { 	0, 0, 0, 0, 0, 1, 0, 0	, 				1, 1, 1, 1, 1, 1, 1, 1   }};*/

	u8 i, j ,k,m,n;
	for (k=0 ; k < 50 ; k++){
		for (i=0 ; i <5 ; i++){
			for (j=0;j<16;j++){
				DIO_u8WritePinVal(26, B[i][j]);
				DIO_u8WritePinVal(24, 1);

			//	_SevenSeg();
				// delay_ms(0.1);
				DIO_u8WritePinVal(24, 0);

			//	_SevenSeg();
				// delay_ms(0.1);
			}
			DIO_u8WritePinVal(25, 1);
			// delay_ms(0.1);SSD_u8TurnOff(SSD_u8DISP1);
		//	_SevenSeg();

			DIO_u8WritePinVal(25, 0);

			//_SevenSeg();
			// delay_ms(0.1);
		}
		_switchHandelr();
		_SevenSeg();
	}


/*	for (k=0;k<iterat;k++){
        m=0;
        for (n = 0; n < 10; n++) {
			for (i = 0; i < Brows; i++) {
				for(j = 0; j < cols; j++)
				 {
					m=j+cols;
					DIO_u8WritePinVal(m, B[i][j]);

					if (m > 23){
					temp[i][m-24]=B[i][j];

						  }
					delay_ms(0.2);

				  }
				delay_ms(.3);
			}
        }

		for (i = 0; i < Brows; i++) {


			for(j = 0; j < phaseIterate; j++)
						 {

				if (temp[i][j]==1){
					temp[i][j]=0;
					temp[i][j+1]=1;
					break;
				}


						 }

			for(j = 0; j < phaseIterate; j++)
						 {

				B[i][j+8]=temp[i][j];
						 }

		}


	}*/

}
void _voidLetterE(void) {
	u8 E[rows][cols] = { { 1, 1, 1, 1, 1, 1, 1, 1,   1, 0, 0, 0, 0, 0, 0, 0 },
						 { 0, 0, 0, 0, 0, 0, 0, 0,   1, 0, 0, 0, 0, 0, 0, 0 },
			             { 0, 1, 1, 1, 0, 1, 1, 0,   0, 1, 0, 0, 0, 0, 0, 0 },
		        	     { 0, 1, 1, 1, 0, 1, 1, 0,   0, 0, 1, 0, 0, 0, 0, 0 },
				         { 0, 1, 1, 1, 0, 1, 1, 0,    0, 0, 0, 1, 0, 0, 0, 0 },
				         { 0, 1, 1, 1, 0, 1, 1, 0,    0, 0, 0, 1, 0, 0, 0, 0 }};

	u8 i, j ,k,m,n;


		for (k=0 ; k < 50 ; k++){
			for (i=0 ; i <5 ; i++){
				for (j=0;j<16;j++){
					DIO_u8WritePinVal(26, E[i][j]);
					DIO_u8WritePinVal(24, 1);
					//_SevenSeg();
					DIO_u8WritePinVal(24, 0);
					//_SevenSeg();
				}
				DIO_u8WritePinVal(25, 1);
				//_SevenSeg();
				DIO_u8WritePinVal(25, 0);
				//_SevenSeg();
			}
			_switchHandelr();
			_SevenSeg();
		}

	/*for (k=0;k<iterat;k++){
        m=0;
        for (n = 0; n < 10; n++) {
			for (i = 0; i < rows; i++) {
				for(j = 0; j < cols; j++)
				 {
					m=j+cols;
					DIO_u8WritePinVal(m, E[i][j]);

					if (m > 23){
					temp[i][m-24]=E[i][j];

						  }
					delay_ms(.2);

				  }
				delay_ms(.5);
			}
        }

		for (i = 0; i < rows; i++) {


			for(j = 0; j < phaseIterate; j++)
						 {

				if (temp[i][j]==1){
					temp[i][j]=0;
					temp[i][j+1]=1;
					break;
				}


						 }

			for(j = 0; j <  phaseIterate; j++)
						 {

				E[i][j+8]=temp[i][j];
						 }

		}


	}*/

}

void _voidLetterL(void) {
	u8 L[rows][cols] = {
						 { 0, 0, 0, 0, 0, 0, 0, 0,   1, 0, 0, 0, 0, 0, 0, 0 },
			             { 0, 1, 1, 1, 1, 1, 1, 1,   0, 1, 0, 0, 0, 0, 0, 0 },
		        	     { 0, 1, 1, 1, 1, 1, 1, 1,   0, 0, 1, 0, 0, 0, 0, 0 },
				         { 0, 1, 1, 1, 1, 1, 1, 1,    0, 0, 0, 1, 0, 0, 0, 0 },
				         { 0, 1, 1, 1, 1, 1, 1, 1,    0, 0, 0, 0, 1, 0, 0, 0 }};



	u8 i, j ,k,m,n;
		for (k=0 ; k < 50 ; k++){
			for (i=0 ; i <5 ; i++){
				for (j=0;j<16;j++){
					DIO_u8WritePinVal(26, L[i][j]);
					DIO_u8WritePinVal(24, 1);
					//_SevenSeg();
					DIO_u8WritePinVal(24, 0);
					//_SevenSeg();
				}
				DIO_u8WritePinVal(25, 1);
				//_SevenSeg();
				DIO_u8WritePinVal(25, 0);
				//_SevenSeg();
			}
			_switchHandelr();
			_SevenSeg();
		}

	/*for (k=0;k<iterat;k++){
        m=0;
        for (n = 0; n < 10; n++) {
			for (i = 0; i < rows; i++) {
				for(j = 0; j < cols; j++)
				 {
					m=j+cols;
					DIO_u8WritePinVal(m, L[i][j]);

					if (m > 23){
					temp[i][m-24]=L[i][j];

						  }
					delay_ms(.2);

				  }
				delay_ms(.5);
			}
        }

		for (i = 0; i < rows; i++) {


			for(j = 0; j < phaseIterate; j++)
						 {

				if (temp[i][j]==1){
					temp[i][j]=0;
					temp[i][j+1]=1;
					break;
				}


						 }

			for(j = 0; j <  phaseIterate; j++)
						 {

				L[i][j+8]=temp[i][j];
						 }

		}


	}
*/
}

void _voidLetterA(void) {
	u8 A[Arows][Acols] = {
						 { 0, 0, 0, 0, 0, 0, 1, 1,     1, 0, 0, 0, 0, 0, 0, 0 },
			             { 1, 1, 1, 1, 1, 0, 0, 1,     0, 1, 0, 0, 0, 0, 0, 0 },
		        	     { 1, 1, 1, 1, 1, 0, 1, 0,     0, 0, 1, 0, 0, 0, 0, 0 },
				         { 1, 1, 1, 1, 1, 0, 0, 1,     0, 0, 0, 1, 0, 0, 0, 0 },
				         { 0, 0, 0, 0, 0, 0, 1, 1,     0, 0, 0, 0, 1, 0, 0, 0 },




		};
	u8 i, j ,k,m,n;
		for (k=0 ; k < 50 ; k++){
			for (i=0 ; i <5 ; i++){
				for (j=0;j<16;j++){
					DIO_u8WritePinVal(26, A[i][j]);
					DIO_u8WritePinVal(24, 1);

					DIO_u8WritePinVal(24, 0);
					//_SevenSeg();
				}
				DIO_u8WritePinVal(25, 1);
				//_SevenSeg();
				DIO_u8WritePinVal(25, 0);
				//_SevenSeg();
			}
			_switchHandelr();
			_SevenSeg();
		}


	/*for (k=0;k<iterat;k++){
        m=0;
        for (n = 0; n < 10; n++) {
			for (i = 0; i < Arows; i++) {
				for(j = 0; j < Acols; j++)
				 {
					m=j+cols;
					DIO_u8WritePinVal(m, A[i][j]);

					if (m > 23){
					temp[i][m-24]=A[i][j];

						  }
					// delay_ms(0.1);

				  }
				delay_ms(0.5);
			}
        }

		for (i = 0; i < Arows; i++) {


			for(j = 0; j < phaseIterate; j++)
						 {

				if (temp[i][j]==1){
					temp[i][j]=0;
					temp[i][j+1]=1;
					break;
				}


						 }

			for(j = 0; j <  phaseIterate; j++)
						 {

			    A[i][j+8]=temp[i][j];
						 }

		}


	}
*/
}


void _SevenSeg(void){


	SSD_u8TurnOff(SSD_u8DISP1);
		SSD_u8TurnOff(SSD_u8DISP2);
		SSD_u8TurnOff(SSD_u8DISP3);
		SSD_u8TurnOff(SSD_u8DISP4);

		SSD_u8Display(SSD_u8DISP1, Local_u8ValueArr[0]);
		SSD_u8TurnOn(SSD_u8DISP1);
		delay_ms(3);
		//_voidLetterB();
		SSD_u8TurnOff(SSD_u8DISP1);

		SSD_u8Display(SSD_u8DISP3, Local_u8ValueArr[1]);
		SSD_u8TurnOn(SSD_u8DISP2);
		delay_ms(3);
		//_voidLetterL();
		SSD_u8TurnOff(SSD_u8DISP2);

		SSD_u8Display(SSD_u8DISP3, Local_u8ValueArr[2]);
		SSD_u8TurnOn(SSD_u8DISP3);
		delay_ms(3);
		//_voidLetterA();
		SSD_u8TurnOff(SSD_u8DISP3);

		SSD_u8Display(SSD_u8DISP4, Local_u8ValueArr[3]);
		SSD_u8TurnOn(SSD_u8DISP4);
		delay_ms(3);
		//_voidLetterL();
		SSD_u8TurnOff(SSD_u8DISP4);

}

void _switchHandelr(void){
	DIO_u8ReadPinVal(DIO_u8PIN4, &Local_u8BtnVal);

			if (Local_u8BtnVal == DIO_u8HIGH && Local_u8BounceFlag == 0) {
				Local_u8BounceFlag = 1;
				//delay_ms(10);
				++Local_u8ValueArr[0];
				if (Local_u8ValueArr[0] > 9) {
					Local_u8ValueArr[0] = 0;
					++Local_u8ValueArr[1];

					if (Local_u8ValueArr[1] > 9) {
						Local_u8ValueArr[1] = 0;
						++Local_u8ValueArr[2];

						if (Local_u8ValueArr[2] > 9) {
							Local_u8ValueArr[2] = 0;
							++Local_u8ValueArr[3];

							if (Local_u8ValueArr[3] > 9) {
								Local_u8ValueArr[3] = 0;
							}
						}

					}
				}

			} else if (Local_u8BtnVal == DIO_u8LOW && Local_u8BounceFlag == 1) {
				Local_u8BounceFlag = 0;
			} else {

			}
}
void Delay(u32 mytime) {
	for (u32 i = mytime; i > 0; i--) {
		for (u32 j = 4000000 / 36000; j > 0; j--) {
			__asm("NOP");
		}
	}
	return;
}

