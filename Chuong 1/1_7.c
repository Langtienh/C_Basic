#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Khai báo mảng chứa các mạo từ, danh từ, động từ, và giới từ
	char *maoTu[] = {"the", "a", "one", "some", "any"};
	char *danhTu[] = {"boy", "girl", "dog", "town", "car"};
	char *dongTu[] = {"drove", "jumped", "ran", "walked", "skipped"};
    char *gioiTu[] = {"on", "under", "over", "beside", "near"};

    // Thiết lập seed cho số ngẫu nhiên
    srand(time(NULL));

    // Sinh ra 10 câu
	int i;
    for (i = 0; i < 10; i++) {
        // Chọn ngẫu nhiên mỗi phần tử từ mỗi mảng
        int maoTuIndex = rand() % 5;
        int danhTuIndex = rand() % 5;
		int danhTuIndex2 = rand() % 5;
        int dongTuIndex = rand() % 5;
        int gioiTuIndex = rand() % 5;

        // In câu
        printf("%s %s %s %s %s.\n", maoTu[maoTuIndex], danhTu[danhTuIndex], dongTu[dongTuIndex], gioiTu[gioiTuIndex], danhTu[danhTuIndex2]);
    }

    return 0;
}
