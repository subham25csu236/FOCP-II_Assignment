#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class MovieTicket {
private:
    // Maps movie ID (Y) to a set of user IDs (X) who have booked tickets
    unordered_map<int, unordered_set<int>> movie_to_users;

public:
    bool book(int x, int y) {
        // Check if the movie is sold out (100 slots maximum)
        if (movie_to_users[y].size() >= 100) {
            return false;
        }
        // Check if the customer has already booked a ticket for this movie
        if (movie_to_users[y].count(x)) {
            return false;
        }
        // Mark the ticket as booked
        movie_to_users[y].insert(x);
        return true;
    }

    bool cancel(int x, int y) {
        // If the customer has not booked a ticket for this movie
        if (!movie_to_users[y].count(x)) {
            return false;
        }
        // Mark the ticket as canceled
        movie_to_users[y].erase(x);
        return true;
    }

    bool is_booked(int x, int y) {
        // Returns true if the user's ID is in the movie's set of booked users
        return movie_to_users[y].count(x) > 0;
    }

    int available_tickets(int y) {
        // Total slots (100) minus the number of booked tickets
        return 100 - movie_to_users[y].size();
    }
}
