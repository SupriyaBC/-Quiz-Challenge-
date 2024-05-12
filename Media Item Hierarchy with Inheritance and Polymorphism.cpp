#include <iostream>
#include <string>

using namespace std;

class MediaItem {
protected:
    string title;

public:
    MediaItem(const string& title)
        : title(title) {
        cout << "MediaItem Constructor: " << title << endl;
    }

    virtual ~MediaItem() {
        cout << "MediaItem Destructor: " << title << endl;
    }
};

class Song : public MediaItem {
private:
    string artist;

public:
    Song(const string& title, const string& artist)
        : MediaItem(title), artist(artist) {
        cout << "Song Constructor: " << title << " by " << artist << endl;
    }

    ~Song() {
        cout << "Song Destructor: " << title << " by " << artist << endl;
    }
};

class Movie : public MediaItem {
private:
    string director;

public:
    Movie(const string& title, const string& director)
        : MediaItem(title), director(director) {
        cout << "Movie Constructor: " << title << " directed by " << director << endl;
    }

    ~Movie() {
        cout << "Movie Destructor: " << title << " directed by " << director << endl;
    }
};

class Book : public MediaItem {
private:
    string author;

public:
    Book(const string& title, const string& author)
        : MediaItem(title), author(author) {
        cout << "Book Constructor: " << title << " by " << author << endl;
    }

    ~Book() {
        cout << "Book Destructor: " << title << " by " << author << endl;
    }
};

int main() {
    string title, artist, director, author;

    cout << "Enter the title of the song: ";
    getline(cin, title);
    cout << "Enter the artist of the song: ";
    getline(cin, artist);
    Song song(title, artist);

    cout << "\nEnter the title of the movie: ";
    getline(cin, title);
    cout << "Enter the director of the movie: ";
    getline(cin, director);
    Movie movie(title, director);

    cout << "\nEnter the title of the book: ";
    getline(cin, title);
    cout << "Enter the author of the book: ";
    getline(cin, author);
    Book book(title, author);

    return 0;
}

