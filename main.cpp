#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> todoList;

void addTask() {
    string description;
    cout << "\nMasukkan deskripsi tugas: ";
    cin.ignore(); // Membersihkan buffer input
    getline(cin, description);
    todoList.push_back({description, false});
    cout << "Tugas berhasil ditambahkan!\n";
}

void viewTasks() {
    if (todoList.empty()) {
        cout << "\nTidak ada tugas dalam daftar.\n";
        return;
    }

    cout << "\nDaftar Tugas:\n";
    for (size_t i = 0; i < todoList.size(); ++i) {
        cout << i + 1 << ". " << todoList[i].description;
        if (todoList[i].completed) {
            cout << " [Selesai]";
        }
        cout << endl;
    }
}

void markTaskCompleted() {
    int index;
    cout << "\nMasukkan nomor tugas yang ingin ditandai selesai: ";
    cin >> index;

    if (index < 1 || index > todoList.size()) {
        cout << "Nomor tugas tidak valid!\n";
        return;
    }

    todoList[index - 1].completed = true;
    cout << "Tugas berhasil ditandai selesai!\n";
}

void deleteTask() {
    int index;
    cout << "\nMasukkan nomor tugas yang ingin dihapus: ";
    cin >> index;

    if (index < 1 || index > todoList.size()) {
        cout << "Nomor tugas tidak valid!\n";
        return;
    }

    todoList.erase(todoList.begin() + index - 1);
    cout << "Tugas berhasil dihapus!\n";
}

int main() {
    int choice;

    do {
        cout << "\n=== To-Do List App ===\n";
        cout << "1. Tambah Tugas\n";
        cout << "2. Lihat Daftar Tugas\n";
        cout << "3. Tandai Tugas Selesai\n";
        cout << "4. Hapus Tugas\n";
        cout << "5. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskCompleted();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                cout << "Keluar dari aplikasi. Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (choice != 5);

    return 0;
}
