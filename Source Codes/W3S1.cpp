#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SINHVIEN
{
	char shsv[15];
	char hoten[100];
	char sdt[15];
	char soMuiTiem;
	char ngayTiemGanNhat[9];
} SV;
// doc danh sach ban dau tu ban phim
// tra ve thong tin danh sach doc duoc va so luong phan tu size
// Khong biet truoc so luong? --> mang cap phat dong nhieu lan
// Ban dau cap phat so luong nho, neu nhu cau them --> cap phat mo rong (gap 2 mang cu)
void nhapDanhSach(SV **list, int *size)
{
	printf("Bat dau nhap thong tin sinh vien tiem chung! (dung nhap khi nhap vao SHSV =0)\n");
	SV *ls;
	int curSize = 10; // khoi tao 1 mang nho 10 phan tu
	ls = (SV*) calloc(curSize, sizeof(SV));
	int i=0;
	char shsv[15];
	while(true)
	{
		printf("Thong tin sinh vien thu %d\n",i+1);
		printf("SHSV:"); fflush(stdin); gets(shsv);
		if(strcmp(shsv,"0")==0) break;
		
		strcpy(ls[i].shsv,shsv);
		printf("Ho ten:"); fflush(stdin); gets(ls[i].hoten);
		printf("So dien thoai:"); fflush(stdin); gets(ls[i].sdt);
		printf("So mui tiem:"); scanf("%d",&ls[i].soMuiTiem);
		printf("Ngay tiem gan nhat YYYYMMDD(neu chua tiem thi nhap vao 0):"); fflush(stdin); gets(ls[i].ngayTiemGanNhat);
		i++;
		
		if(i>curSize) // resize mang moi de co the nhap them
		{
			curSize = 2*curSize;
			ls = (SV *) realloc(ls, curSize*sizeof(SV)); // tang gap 2 mang cu
		}
	}
	// neu can co the resize lai mang cho bang dung kich thuoc that (tranh lang phi)
	ls = (SV *) realloc(ls, i*sizeof(SV));
	
	*list = ls;
	*size = i; // currSize la kich thuoc toi da cua mang hien tai	
}

// trong ham se cap phat dopng 1 vung nho moi cho mang list --> can truy vao la dia chi cua con tro list
// bien don gian nhu kieu int, muon thay doi gia tri trong ham --> truyen vao dia chi *int
// neu muon thay doi gia tri cua vung nho mang *int --> can truyen vao dia chi vung nho do --> **int 
void nhapDanhSach_Basic(SV **list, int *size)
{
	int n;
	SV *ls;
	printf("So luong sinh vien can nhap: ");
	scanf("%d",&n);
	//ls = (SV*) malloc(n*sizeof(SV));
	ls = (SV*) calloc(n, sizeof(SV));
	printf("Bat dau nhap thong tin sinh vien tiem chung!\n");
	for(int i=0; i<n; i++)
	{
		printf("Thong tin sinh vien thu %d\n",i+1);
		printf("SHSV:"); fflush(stdin); gets(ls[i].shsv);
		printf("Ho ten:"); fflush(stdin); gets(ls[i].hoten);
		printf("So dien thoai:"); fflush(stdin); gets(ls[i].sdt);
		printf("So mui tiem:"); scanf("%d",&ls[i].soMuiTiem);
		printf("Ngay tiem gan nhat YYYYMMDD(neu chua tiem thi nhap vao 0):"); fflush(stdin); gets(ls[i].ngayTiemGanNhat);
	}
	// khi tra ve
	*list = ls;
	*size = n;
}

// in ra thogn tin danh sach hien co
void inDanhSach(const SV *list, int size)
{
	printf("Hien co %d sinh vien trong danh sach\n",size);
	printf("Thong tin chi tiet: \n");
	for(int i=0; i<size; i++)
		printf("%s %s %s %2d %s\n",list[i].shsv,list[i].hoten,list[i].sdt,list[i].soMuiTiem ,list[i].ngayTiemGanNhat);
	
	printf("\n");
}

// Ghi noi dung danh sach hien tai ra file nhi phan
void GhiFileNhiPhan(char *filename, const SV *list, int size)
{
	FILE *fptr; 
	if ((fptr = fopen(filename, "wb")) == NULL){
		printf("Cannot open %s.\n", filename);
		return;
    }
    // ghi so luong phan tu
    fwrite(&size, sizeof(int), 1, fptr);
    
	// ghi toan bo cac phan tu vao file 
    int n = fwrite(list, sizeof(SV), size, fptr);
    printf("Da luu thanh cong %d phan tu vao file!\n",n);
    
    // dong file
    fclose(fptr);
} 

// tim va in ra thong tin sinh vien theo SHSV neu co
void traCuuThongTinTheoSHSV(const SV *list, int size, const char *shsv)
{
	
}

// tim va in ra thong tin sinh vien theo SDT neu co
void traCuuThongTinTheoSHSV(const SV *list, int size, const char *sdt)
{
	
}


// ham bo sung them thong tin moi cho danh sach
// doc vao SHSV, neu SHSV chua ton tai --> them phan tu moi (them vao cuoi)
// neu da ton tai --> update so mui tiem va ngay tiem gan nhat
// mang da du, muon luwu them --> phai thay doi kich thuoc!
// realloc them 10 phan tu nua (thuc te nen la nhan gap 2 so luong phan tu hien co)
// realloc(void *ptr, size_t size) 
// voi kich thuoc moi size =2*size
void capNhatDanhSach(SV **list, int *size)
{
	
}

// sap xep danh sach sinh vien hien co theo thu tu tang dan SHSV
// dieu chinh noi dung mang list, chi can truyen vao *list
void sapSepDanhSachTheoSHSV(SV *list, int size)
{
	
}

// Doc noi dung tu file nhi phan
void docDanhSach(char *filename, SV **list, int *size)
{
	FILE *fptr; 
	if ((fptr = fopen(filename, "rb")) == NULL){
		printf("Cannot open %s.\n", filename);
		return;
    }
    int n; 
    // doc so luong phan tu
    fread(&n, sizeof(int), 1, fptr);
    
    SV *ls = (SV*) calloc(n, sizeof(SV));
    
	// doc toan bo cac phan tu vao file 
    int count = fread(ls, sizeof(SV), n, fptr);
    printf("Da doc thanh cong %d phan tu vao danh sach!\n",count);
    
    // dong file
    fclose(fptr);
    
    // cap nhat gia tri vao tham so tra ve
    *size = count;
    *list = ls;
}
int main()
{
	SV *list;
	int size;
	//nhapDanhSach_Basic(&list, &size);
	//nhapDanhSach(&list, &size);
	docDanhSach("outputdata.dat",&list, &size);
	inDanhSach(list, size);
	//GhiFileNhiPhan("outputdata.dat",list, size);
	
	return 0;
}

