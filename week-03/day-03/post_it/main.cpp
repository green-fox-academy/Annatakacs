#include <iostream>
#include "postit.h"

//
//* Create a PostIt class that has
//÷ a backgroundColor
//* a text on it
//* a textColor
//* Create a few example post-it objects:
//* an orange with blue text: "Idea 1"
//* a pink with black text: "Awesome"
//* a yellow with green text: "Superb!"
//

int main()
{
    Postit note1 ("orange", "Idea 1", "blue");
    Postit note2 ("pink", "Awesome", "black");
    Postit note3 ("yellow", "Superb!", "green");


    return 0;
}