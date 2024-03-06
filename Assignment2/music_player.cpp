#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Song {
 private:
  string title;
  string artist;

 public:
  Song(string title, string artist) : title(title), artist(artist) {}

  string getTitle() const {
    return title;
  }
  string getArtist() const {
    return artist;
  }
};

class DLLNode {
 private:
  unique_ptr<Song> song;
  shared_ptr<DLLNode> prev;
  shared_ptr<DLLNode> next;

 public:
  DLLNode(unique_ptr<Song> song)
      : song(std::move(song)), prev(nullptr), next(nullptr) {}

  void setPrev(shared_ptr<DLLNode> prev) {
    this->prev = prev;
  }
  void setNext(shared_ptr<DLLNode> next) {
    this->next = next;
  }

  shared_ptr<DLLNode> getPrev() const {
    return prev;
  }
  shared_ptr<DLLNode> getNext() const {
    return next;
  }

  Song* getSong() const {
    return song.get();
  }
};

class MusicPlayer {
 private:
  shared_ptr<DLLNode> head;
  shared_ptr<DLLNode> tail;
  shared_ptr<DLLNode> current;

 public:
  MusicPlayer() : head(nullptr), tail(nullptr), current(nullptr) {}

  void addSong(unique_ptr<Song> song) {
    auto newNode = make_shared<DLLNode>(std::move(song));
    if (!head) {
      head = tail = newNode;
    } else {
      tail->setNext(newNode);
      newNode->setPrev(tail);
      tail = newNode;
    }
    if (!current) current = head;
  }

  void playSong() {
    if (current)
      cout << "Playing: " << current->getSong()->getTitle() << " by "
           << current->getSong()->getArtist() << endl;
    else
      cout << "No song is currently selected." << endl;
  }

  void playNext() {
    if (current && current->getNext()) {
      current = current->getNext();
      playSong();
    } else {
      cout << "No more songs to play." << endl;
    }
  }

  void playPrev() {
    if (current && current->getPrev()) {
      current = current->getPrev();
      playSong();
    } else {
      cout << "No more songs to play." << endl;
    }
  }

  void displayPlaylist() {
    if (!head) {
      cout << "No songs on the playlist." << endl;
      return;
    }

    cout << "Playlist:" << endl;
    auto temp = head;
    while (temp) {
      cout << temp->getSong()->getTitle() << " by "
           << temp->getSong()->getArtist() << endl;
      temp = temp->getNext();
    }
  }

  bool isEmpty() const {
    return head == nullptr;
  }
};

int main() {
  MusicPlayer mp;
  char choice;
  string title, artist;

  do {
    cout << "\nMusic Player Menu:" << endl;
    cout << "1. Add a Song" << endl;
    cout << "2. Play Song" << endl;
    cout << "3. Play Next" << endl;
    cout << "4. Play Previous" << endl;
    cout << "5. Display Playlist" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case '1':
        cout << "Enter song title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter artist name: ";
        getline(cin, artist);
        mp.addSong(make_unique<Song>(title, artist));
        cout << "Song added successfully!" << endl;
        break;
      case '2':
        if (mp.isEmpty())
          cout << "No songs on the playlist. Cannot play." << endl;
        else
          mp.playSong();
        break;
      case '3':
        mp.playNext();
        break;
      case '4':
        mp.playPrev();
        break;
      case '5':
        mp.displayPlaylist();
        break;
      case '6':
        cout << "Exiting..." << endl;
        break;
      default:
        cout << "Invalid choice. Please enter a valid option." << endl;
    }
  } while (choice != '6');

  return 0;
}