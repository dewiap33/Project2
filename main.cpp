#include <iostream>
#include <iomanip>
#include <string>

int main() {
    std::string gejala[10][2] = {
        {"G1", "Batuk Berdahak"},
        {"G2", "Batuk Berdarah"},
        {"G3", "Sesak Nafas"},
        {"G4", "Nyeri Dada"},
        {"G5", "Tidak Nafsu Makan"},
        {"G6", "Penurunan Berat Badan"},
        {"G7", "Demam dan Menggigil"},
        {"G8", "Keringat Berlebih Di Malam Hari"},
        {"G9", "Sering Kelelahan"}
    };

    std::string pasienB[9];
    const int jumlahPasien = 16;
    std::string diagnosa[16][11] = {
        {"Aldi", "1", "1", "1", "1", "1", "1", "1", "1", "1", "Positif"},
        {"Inal", "1", "0", "0", "0", "0", "0", "0", "1", "0", "Negatif"},
        {"Jiki", "1", "1", "1", "1", "0", "1", "1", "1", "1", "Positif"},
        {"Upin", "1", "0", "0", "0", "0", "0", "0", "0", "0", "Negatif"},
        {"Agus", "1", "0", "1", "1", "1", "1", "1", "1", "1", "Positif"},
        {"Roma", "0", "1", "0", "0", "0", "0", "0", "0", "0", "Negatif"},
        {"Ipin", "1", "1", "1", "1", "1", "1", "1", "0", "1", "Positif"},
        {"Rama", "0", "0", "1", "0", "0", "0", "0", "0", "0", "Negatif"},
        {"Jisa", "0", "1", "1", "1", "1", "1", "1", "1", "1", "Positif"},
        {"Raja", "0", "0", "0", "1", "0", "0", "0", "0", "0", "Negatif"},
        {"Jusi", "1", "1", "1", "1", "1", "1", "0", "1", "1", "Positif"},
        {"Daki", "0", "0", "0", "0", "1", "0", "0", "0", "0", "Negatif"},
        {"Agun", "1", "1", "1", "1", "1", "0", "1", "1", "1", "Positif"},
        {"Duta", "0", "0", "0", "0", "0", "1", "0", "0", "0", "Negatif"},
        {"Udin", "0", "1", "1", "1", "1", "1", "1", "1", "0", "Positif"},
        {"Josi", "0", "0", "0", "0", "0", "0", "1", "0", "0", "Negatif"}
    };

    int nBaris = sizeof(diagnosa) / sizeof(diagnosa[0]);

    char menu;
    do {
        std::cout << "================================================" << std::endl;
        std::cout << "|       Aplikasi Diagnosis Penyakit Paru       |" << std::endl;
        std::cout << "------------------------------------------------" << std::endl;
        std::cout << "| [A]. Dataset Kasus Penyakit Paru             |" << std::endl;
        std::cout << "| [B]. Konsultasi dan Diagnosis                |" << std::endl;
        std::cout << "| [C]. KELUAR                                  |" << std::endl;
        std::cout << "================================================" << std::endl;
        std::cout << "  Pilih Menu [A/B/C]? : ";
        std::cin >> menu;

        switch (tolower(menu)) {
            case 'a':
    		    std::cout << "===========================================================================================================" << std::endl;
   				std::cout << "| Pasien | Nama Pasien   |";
    			for (int j = 0; j < 9; j++) {
    			    std::cout << std::setw(6) << gejala[j][0] << " |";
   				}
    			std::cout << " Hasil  |" << std::endl;
    			std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;
    			for (int j = 0; j < jumlahPasien; j++) {
    			    std::cout << "|" << std::setw(6) << diagnosa[j][0] << " |";
    			    std::cout << std::setw(15) << diagnosa[j][0] << " |";
    			    for (int i = 0; i < 10; i++) {
    			        if (diagnosa[j][i + 1] == "1") {
    			            diagnosa[j][i + 1] = "Ya";
    			            std::cout << std::right << std::setw(6) << diagnosa[j][i + 1] << " |";
    			        } else if (diagnosa[j][i + 1] == "0") {
    			            diagnosa[j][i + 1] = "Tidak";
    			            std::cout << std::right << std::setw(6) << diagnosa[j][i + 1] << " |";
    			        }
    			    }
    			    std::cout << diagnosa[j][10] << " |" << std::endl;
    			}
    			break;
            case 'b':
                {
                    std::cout << "nama pasien yang konsultasi: ";
                    std::string pasien;
                    std::cin >> pasien;

                    double maxSimilarity = 0.0;
                    std::string mostSimilarPatient;

                    for (int j = 0; j < 9; j++) {
                        char response;
                        std::cout << gejala[j][1] << " (y/n): ";
                        std::cin >> response;
                        pasienB[j] = response == 'y' ? "1" : "0";
                    }

                    std::cout << "-------------------------------------------------------------" << std::endl;
                    std::cout << "| Gejala untuk pasien: " << std::setw(8) << pasien << "\t\t\t\t\t|" << std::endl;
                    std::cout << "-------------------------------------------------------------" << std::endl;
                    std::cout << "| ID\t| Nama Gejala\t\t\tt| Jawaban\t|" << std::setw(15) << std::endl;
                    std::cout << "-------------------------------------------------------------" << std::endl;

                    for (int j = 0; j < 9; j++) {
                        std::cout << "|" << std::setw(6) << gejala[j][0] << "\t|";
                        std::cout << std::setw(32) << gejala[j][1] << "  |";
                        std::cout << std::setw(15) << (pasienB[j] == "1" ? "Ya" : "Tidak") << "|" << std::endl;
                    }
                    std::cout << "-------------------------------------------------------------" << std::endl;

                    std::cout << "=============================================================" << std::endl;
                    std::cout << "|\tTingkat Kemiripan Data Pasien dengan " << pasien << "\t|" << std::endl;
                    std::cout << "-------------------------------------------------------------" << std::endl;

                    double a = 0, b = 0, c = 0;

                    for (int j = 0; j < 9; j++) {
                        if (pasienB[j] == "1") {
                            if (diagnosa[0][j + 1] == "1") {
                                a++;
                            } else {
                                b++;
                            }
                        } else if (diagnosa[0][j + 1] == "1") {
                            c++;
                        }
                    }
                    double similarity = 1 - (b + c) / (a + b + c);
                    double similarityPercentage = similarity * 100;
                    std::cout << "| sim(" << pasien << "," << diagnosa[0][0] << ") = 1-(" << b << "+" << c << "/" << a + b + c << ") = " << std::setprecision(3) << similarityPercentage << "%" << std::endl;
                    for (int i = 1; i < jumlahPasien; i++) {
                        a = b = c = 0;
                        for (int j = 0; j < 9; j++) {
                            if (pasienB[j] == "1") {
                                if (diagnosa[i][j + 1] == "1") {
                                    a++;
                                } else {
                                    b++;
                                }
                            } else if (diagnosa[i][j + 1] == "1") {
                                c++;
                            }
                        }
                        similarity = 1 - (b + c) / (a + b + c);
                        similarityPercentage = similarity * 100;
                        std::cout << "| sim(" << pasien << "," << diagnosa[i][0] << ") = 1-(" << b << "+" << c << "/" << a + b + c << ") = " << std::setprecision(3) << similarityPercentage << "%" << std::endl;
                        if (similarity > maxSimilarity) {
                            maxSimilarity = similarity;
                            mostSimilarPatient = diagnosa[i][0];
                        }
                    }

                    std::cout << "|---------------------------------------------|" << std::endl;
                    std::cout << "===============================================" << std::endl;
                    std::cout << "\t\tHasil Konsultasi\t\t|" << std::endl;
                    std::cout << "|---------------------------------------------|" << std::endl;
                    std::cout << "| Nama Pasien                 = " << pasien << std::endl;
                    std::cout << "| Kesamaan rekam medis dengan = " << mostSimilarPatient << std::endl;
                    std::cout << "| Tingkat Kemiripan           = " << std::setprecision(3) << maxSimilarity * 100 << "%" << std::endl;
                    std::cout << "| Hasil Diagnosa              = " << diagnosa[0][10] << " Paru" << std::endl;
                    std::cout << "|---------------------------------------------|" << std::endl;
                    std::cout << std::endl;
                    std::cout << "Kembali ke menu utama? [Y/N] : ";
                    char backToMainMenu;
                    std::cin >> backToMainMenu;
                    if (tolower(backToMainMenu) == 'n') {
                        return 0;
                    }
                }
                break;

            case 'c':
                char pilih;
                std::cout << "================================================" << std::endl;
                std::cout << " Apakah Ingin Keluar [Y/N] : ";
                std::cin >> pilih;
                if (pilih == 'Y' || pilih == 'y') {
                    return 0;
                }
                break;
            default:
                std::cout << "Input Salah !" << std::endl;
                break;
        }
    } while (menu != 'C');

    return 0;
}

