#include <stdio.h>
#include <stdlib.h>
#include "file_test.h"
#include <assert.h>
#include <errno.h>
// ����һ���ṹ�����������ں�������Ϣ
typedef struct {
    int year;
    int month;
    int day;
    char weather[50];
} WeatherRecord;

void writeRecord(const char* filename, WeatherRecord* record) {
    // ���ļ�����д����
    FILE* file;
    errno_t err = fopen_s(&file, filename, "wb");
    if (err != 0) {
        perror("�޷����ļ�����д����");
        exit(EXIT_FAILURE);
    }
    // ���ṹ��д���ļ�
    size_t written = fwrite(record, sizeof(WeatherRecord), 1, file);
    if (written != 1) {
        perror("д���ļ�ʱ����");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    fclose(file);
}

void readRecord(const char* filename, WeatherRecord* record) {
    // ���ļ����ж�����
    FILE* file;
    errno_t err = fopen_s(&file, filename, "rb");
    if (err != 0) {
        perror("�޷����ļ����ж�����");
        exit(EXIT_FAILURE);
    }
    // ���ļ��ж�ȡ�ṹ��
    size_t read = fread(record, sizeof(WeatherRecord), 1, file);
    if (read != 1) {
        perror("��ȡ�ļ�ʱ����");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    fclose(file);
}

int file_test_main() {
    // ����һ��WeatherRecordʵ�����������
    WeatherRecord today = { 2024, 6, 20, "����" };

    // �����ļ���
    const char* filename = "weather.dat";

    // ���ṹ��д���ļ�
    writeRecord(filename, &today);

    // ���ļ��ж�ȡ�ṹ��
    WeatherRecord read_today;
    readRecord(filename, &read_today);

    // ��ʾ��ȡ��������
    printf("����: %d-%02d-%02d\n", read_today.year, read_today.month, read_today.day);
    printf("����: %s\n", read_today.weather);

    return 0;
}

void file_test()  // file create, open,write
{
        const int SIZE = 5;
        double a[SIZE] = { 1, 2, 3, 4, 5 };
        FILE* file;
        errno_t err_open = fopen_s(&file, "/file.bin", "wb");
        if (err_open != 0) {
            perror("Failed to open file for writing");
            exit(EXIT_FAILURE);
        }

        size_t r1 = fwrite(a, sizeof(a[0]), SIZE, file);
        printf("wrote %zu elements out of %d requested\n", r1, SIZE);
        fclose(file);

        double b[SIZE];
        FILE* f2;
        errno_t err = fopen_s(&f2, "file.bin", "rb");
        if (err != 0) {
            perror("Failed to open file for reading");
            exit(EXIT_FAILURE);
        }

        size_t r2 = fread(b, sizeof(b[0]), SIZE, f2);
        if (r2 != SIZE) {
            perror("Failed to read the expected number of elements");
            fclose(f2);
            exit(EXIT_FAILURE);
        }

        fclose(f2);
        printf("read back: ");
        for (size_t i = 0; i < SIZE; ++i) {
            printf("%0.2f ", b[i]);
        }
        printf("\n");      
}

