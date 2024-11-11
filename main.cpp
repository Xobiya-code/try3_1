// Song-playlist
#include <iostream>
#include <string>

using namespace std;

// Define the structure for a song
struct Song {
    string title;
    string artist;
    Song* next;
};

// Function to insert a song at the beginning of the playlist
void insertAtBeginning(Song*& head, const string& title, const string& artist) {
    Song* newSong = new Song{title, artist, head};
    head = newSong;
}

// Function to insert a song at the end of the playlist
void insertAtEnd(Song*& head, const string& title, const string& artist) {
    Song* newSong = new Song{title, artist, nullptr};
    if (head == nullptr) {
        head = newSong;
    } else {
        Song* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newSong;
    }
}

// Function to insert a song at a specific position in the playlist
void insertAtPosition(Song*& head, const string& title, const string& artist, int position) {
    if (position <= 0) {
        cout << "Position must be greater than 0." << endl;
        return;
    }
    if (position == 1) {
        insertAtBeginning(head, title, artist);
        return;
    }
    Song* newSong = new Song{title, artist, nullptr};
    Song* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; ++i) {
        temp = temp->next;
    }
    if (temp != nullptr) {
        newSong->next = temp->next;
        temp->next = newSong;
    } else {
        cout << "Position out of bounds." << endl;
    }
}

// Function to delete a song from the beginning of the playlist
void deleteAtBeginning(Song*& head) {
    if (head == nullptr) {
        cout << "Playlist is empty." << endl;
        return;
    }
    Song* temp = head;
    head = head->next;
    delete temp;
}

// Function to delete a song from the end of the playlist
void deleteAtEnd(Song*& head) {
    if (head == nullptr) {
        cout << "Playlist is empty." << endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        Song* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
}

// Function to delete a song from a specific position in the playlist
void deleteAtPosition(Song*& head, int position) {
    if (position <= 0) {
        cout << "Position must be greater than 0." << endl;
        return;
    }
    if (position == 1) {
        deleteAtBeginning(head);
        return;
    }
    Song* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; ++i) {
        temp = temp->next;
    }
    if (temp != nullptr && temp->next != nullptr) {
        Song* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    } else {
        cout << "Position out of bounds." << endl;
    }
}

// Function to display the playlist
void displayPlaylist(Song* head) {
    if (head == nullptr) {
        cout << "Playlist is empty." << endl;
        return;
    }
    Song* temp = head;
    while (temp != nullptr) {
        cout << temp->title << " by " << temp->artist << endl;
        temp = temp->next;
    }
}

int main() {
    Song* playlist = nullptr;
    int choice, position;
    string title, artist;

    do {
        cout << "\nMusic Playlist Menu:\n";
        cout << "1. Insert a song at the beginning\n";
        cout << "2. Insert a song at the end\n";
        cout << "3. Insert a song at a specific position\n";
        cout << "4. Delete a song from the beginning\n";
        cout << "5. Delete a song from the end\n";
        cout << "6. Delete a song from a specific position\n";
        cout << "7. Display the playlist\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the song title: ";
                cin >> ws; // To ignore leading whitespaces
                getline(cin, title);
                cout << "Enter the artist name: ";
                getline(cin, artist);
                insertAtBeginning(playlist, title, artist);
                break;
            case 2:
                cout << "Enter the song title: ";
                cin >> ws;
                getline(cin, title);
                cout << "Enter the artist name: ";
                getline(cin, artist);
                insertAtEnd(playlist, title, artist);
                break;
            case 3:
                cout << "Enter the position: ";
                cin >> position;
                cout << "Enter the song title: ";
                cin >> ws;
                getline(cin, title);
                cout << "Enter the artist name: ";
                getline(cin, artist);
                insertAtPosition(playlist, title, artist, position);
                break;
            case 4:
                deleteAtBeginning(playlist);
                break;
            case 5:
                deleteAtEnd(playlist);
                break;
            case 6:
                cout << "Enter the position: ";
                cin >> position;
                deleteAtPosition(playlist, position);
                break;
            case 7:
                displayPlaylist(playlist);
                break;
            case 8:
                cout << "Exiting the application.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
