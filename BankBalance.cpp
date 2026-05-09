
int main() {
    int q;
    if (!(cin >> q)) return 0;
    
    MovieTicket mt;
    
    while (q--) {
        string query_type;
        cin >> query_type;
        
        if (query_type == "BOOK") {
            int x, y;
            cin >> x >> y;
            cout << (mt.book(x, y) ? "true" : "false") << "\n";
        } 
        else if (query_type == "CANCEL") {
            int x, y;
            cin >> x >> y;
            cout << (mt.cancel(x, y) ? "true" : "false") << "\n";
        } 
        else if (query_type == "IS_BOOKED") {
            int x, y;
            cin >> x >> y;
            cout << (mt.is_booked(x, y) ? "true" : "false") << "\n";
        } 
        else if (query_type == "AVAILABLE_TICKETS") {
            int y;
            cin >> y;
            cout << mt.available_tickets(y) << "\n";
        }
    }
    
    return 0;
}
