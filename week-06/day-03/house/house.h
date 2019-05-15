#ifndef HOUSE_HOUSE_H
#define HOUSE_HOUSE_H

typedef struct house {
    char address[50];
    int price;
    int rooms;
    double area;
} house_t;

int is_worth_it(house_t *house1)
{
    int market_price = 400;
    if (house1->price < market_price) {
        return 1;
    } else
        return 0;
}

int count_worthy_houses(house_t house1[], int size)
{
    int counter = 0;
    for (int i = 0; i < size; ++i) {
        if (is_worth_it(&house1[i]) == 1) {
            //printf("%s\n", house1[i].address);
            counter++;
        }
    }
    return counter;
}

#endif //HOUSE_HOUSE_H
