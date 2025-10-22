[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/pAwGQi_N)

# PA4 Skeleton Code
We expect a fully functioninig command line REPL application for an inventory querying system. Feel free to modify the skeleton code as you see fit.

### How to run the current skeleton code
`make` will compile and execute the skeleton code

Feel free to modify Makefile as you see fit.

log date: 10-22-25

Looking through a few lines of the amazon csv, I noticed it’s kind of messy
so i’m planning to do some cleanup before actually loading it into my program.

i’m thinking of removing the extra quotes around text since some product names
have weird double quotes like 41"" bamboo. i’ll probably replace those double
quotes with just one so it looks normal.

for the category field, i saw it uses | to separate things like Sports &Outdoors |
Outdoor Recreation. i might split those by the pipe symbol and trim the spaces, so
each category looks clean and easier to match when someone types it in later.

some rows don’t have a category at all, so i’m considering putting "NA" for those
instead of leaving them blank. that way every product still has something i can
group it under.

if a row doesn’t have a Uniq Id, i’ll most likely skip it because that’s what i’ll
use as the main key for searching.

I also noticed there are a bunch of other columns like product descriptions, image
links, and dimensions. i probably won’t use those since the assignment only needs
the id, product name, and category. leaving them out should make the program load
faster too.

for categories, i’m still deciding whether to lowercase them all or just leave
them how they are. lowercase might make searching easier, but i don’t want to mess
with how the original data looks too much.

Basically just trying to keep the data simple and consistent so i don’t run into problems when doing find and listInventory.
