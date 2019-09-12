#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

typedef char string[15];

int Kembalian(int pembayaran, int total_spp_variable);
int spp(int sks);
int jatahsks(float ip);



int main()
{
	int pilih,nim,angkat,sks,total_spp_variable,pembayaran,jatah_sks;
	string nama;
	float ip;
		
	do
	{
		system("cls");
		printf("\n0. Keluar");
		printf("\n1. Input Data");
		printf("\n2. Tampilkan Data");
		printf("\n3. Pengambilan SKS");
		printf("\n4. sks Variable");
		printf("\n5. Pembayaran");
		printf("\n=>Inputkan Pilihan : "); scanf("%d",&pilih);

		switch(pilih)
		{
			case 1 :
					printf("\nMasukan Nama : "); fflush(stdin);gets(nama);

					do
					{
							printf("\nMasukan NIM : "); scanf("%d",&nim);	
							
								if(nim<1000 || nim>9999)

									{
										printf("Masukan 4 Digit Angka!!!");
									}

					}while(nim<1000 || nim>9999);	

					do
					{
						printf("\nMasukan IP : "); scanf("%f",&ip);
								if(ip<0 || ip>4)
									{
									printf("Range IP adalah 0-4!!");
									}

					}while(ip<0 || ip>4);

					

					do
					{
						printf("\nMasukan Angkatan : "); scanf("%d",&angkat);
					}while(angkat<2005 || angkat>2014);

					
					printf("\nData sudah dicatat!!!");
					break;

					

			case 2 :	
					nim=(angkat%100)*10000000+700000+nim;
					printf("\nData %s <%d> :  ",nama,nim);
					printf("\nAngkatan : %d ",angkat);
					printf("\nIP : %.2f ",ip);
					printf("\nJatah SKS : %d SKS",jatahsks(ip));
						
					break;

			case 3 :
					printf("\nJatah SKS %s <%d> semester ini = %d",nama,nim,jatahsks(ip));
					printf("\nBerapa SKS yang mau diambil ?"); scanf("%d",&sks);	
					printf("\n%d mengambil %d SKS semester ini.",nim,sks);
					break;

			case 4 :
					printf("\nYang Terhormat,");
					printf("\n%s",nama);	
					printf("\nAnda mengambil %d SKS semester ini.",sks);
					printf("\nRincian biaya = %d x 130.000 = %d",sks,spp(sks));
					printf("\nSPP variable yang harus dibayarkan adalah Rp.%d,-",spp(sks));
					break;

			case 5 :
					total_spp_variable=spp(sks);
					printf("sks Variable yang harus dibayar adalah %d, \n-Masukan Nominal Pembayaran = Rp",total_spp_variable); scanf("%d",&pembayaran);
					do
					{
						printf("Kembalian : Rp%d",Kembalian(pembayaran,total_spp_variable) );	
					}while(pembayaran<total_spp_variable);
					break;
				
		}getch();
	}while(pilih!=0);
}



int spp(int sks)
{
	return sks*130000;
}

int jatahsks(float ip)
{
	int temp;
			if(ip<2.00)
		{
			temp=15;
		}else if(ip>=2.00&&ip<2.50)
									
		{
			temp=18;
		}else if(ip>=2.50&&ip<3.00)
									
		{
			temp=21;
		}else if(ip>=3.00)
								
		{
			temp=24;
		}		
		return temp;
} 

int Kembalian(int pembayaran, int total_spp_variable)
{
	return pembayaran - total_spp_variable;
}









