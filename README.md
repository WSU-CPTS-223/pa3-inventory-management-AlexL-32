[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/pAwGQi_N)

# PA4 Skeleton Code
We expect a fully functioninig command line REPL application for an inventory querying system. Feel free to modify the skeleton code as you see fit.

### How to run the current skeleton code
`make` will compile and execute the skeleton code

Feel free to modify Makefile as you see fit.

Parsing self Discussion:

Looking through a few lines of the amazon csv, I noticed it’s kind of messy
however i only need to read up to category ignoring brand name and asin
which seem to be empty which is good.

looking at some of the product names, some of them have commas in the string so ill have
to create a safeguard if a case like that were to occur. I’ll ignore the first " and grab the string up
to the matching " instead of just stopping at a comma, since commas can appear in the name itself.
Then I’ll move past the closing quote and skip the comma that follows it.
UPDATE: I see product names have multiple quotes in the name such as
"Oopsy Daisy Birchwood Owl Growth Chart, Pink, 12"" x 42""" so im gonna have to alter my parser to also
account for this. I can probably have a loop going where the end index keeps trying to find " until it
can’t find any more. If I find two quotes in a row "" I’ll just skip them since that means there’s an
actual quote in the name. When I finally find a quote that isn’t followed by another quote, I’ll know
I’ve reached the closing quote. I’ll probably create some helper functions for the parser since the function
is getting more complex.
2nd UPDATE: ok so now im seeing product names with multiple sets of quotes and commas, for example
"Weiler 14506 Nylox Cup Brush, 6"", 0.40/80SC Crimped Fill, 5/8""-11 UNC Nut"
so now my parser has to handle both commas and escaped quotes inside quoted names. The loop should keep
searching for the closing quote and skip any doubled quotes so it doesn’t stop too early.
for the category field, i saw it uses | to separate things like Sports &Outdoors |
Outdoor Recreation. i try spliting those by the bar symbol and trim the spaces, so
each category looks clean and easier to match when user types it in later for listInventory <category_string>.

some rows don’t have a category at all, Ill try putting "NA" for those
instead of leaving them blank like recommended. that way every product still has something i can
group it under.

if a row doesn’t have a Uniq Id, i’ll most likely skip it because that’s what i’ll
use as the main key for searching.

I also noticed there are a bunch of other columns like product descriptions, image
links, and dimensions. i probably won’t use those since the assignment only needs
the id, product name, and category.

Basically Im just trying to clean up the data especially the categoires so i don’t run into problems when doing find and listInventory.


Testing direction:

So for testing I just wanted to make sure the basic parts of my program actually work before doing the bigger stuff.
I have the parser, the list, and the hash table, so i tried to test each one kind of like how i’d actually use it.
i’m not trying to do some perfect coverage thing, just enough to catch the easy mistakes and make sure the logic makes sense.

for the parser, i made a few lines that looked like the the amazon csv and tried to hit the main situations i’d see.
i did a normal one that just has regular quotes and categories (simpleParse), then one that has a comma inside
the name since that’s what broke my code before (quotedNameParse). i also tried a line with no category so it makes
sure to put “N/A” instead of blank, and another one with spaces around the category bar | so i know it’s trimming them right.

then for the data structures, i didn’t test as much as i should have, I just tested insert and search for my list, and insert/find for the hash table. i added a few values, checked that the right ones come back, and that a missing one returns false instead of crashing. that’s basically all i need since that’s how i use them in the real program. i thought about writing more tests for the ref functions (searchRef and findRef) just to prove that when i change something through a pointer it actually updates the value in the node or list, but i ran out of time and need to turn this in. maybe i’ll do that later.

honestly you can’t test every single possible input anyway, especially with csv data this messy. all i can do is test the base cases normal, edge, and errors and make sure it handles those without breaking. if something weird shows up later, it’ll probably be from the data itself, not from my containers. all my tests pass, so i think it’s good enough to move on.