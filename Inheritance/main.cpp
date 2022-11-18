#include "destination_country.hpp"

int main(int argc, const char * argv[]) {
    table white, blue("metal", 2, 2.4, 6);
    chair red;
    table yellow;
    country where;
    imported * country = new table;
    
    std::cout << where.destination_country(new chair) <<" \n";
    std::cout << country->is_imported() <<" \n";

    std::cout << white.price() <<" \n";
    std::cout << white.currency() <<" \n";
    std::cout << blue.price() <<" \n";
    std::cout << blue.currency() <<" \n";
    return 0;
}
