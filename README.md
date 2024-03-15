# Algorithmic-problems

1. FERRY

A convoy of N cars must cross a river (keeping the order from
convoy) using the ferry, and a total of K ferries are available. We know about the i-a
the car has the weight of G_i
. A ferry can support any number of cars, but the cost of
its crossing is equal to the sum of the weights of all the cars that
transport. We denote by C_i the cost for ferry i.
Taking into account that the K ferries must pass all cars on the opposite side
of the river, each making a single path, which is its lowest possible value
C, where C is the maximum of C_1, C_2, . . . , C_k?

2. SUSHI

We are going to eat sushi with (N-1) friends. I'm at the restaurant
M sushi platters available, each platter with a cost C_i. Both you and friends
you have certain food preferences, so each person gave a score from 1 to
10 for each sushi option (Friend number i gave plate number j a grade G_ij).
You also have a fairly fixed budget, so you have decided that each of you will
contribute a maximum of X lei for the meal (so in total N ∗ X lei for the entire grade of
the payment).
You are responsible for placing the order and you would like to choose the menus so that
you maximize the sum of the marks given by you and your friends for the plates ordered. If one
plate is ordered for example 2 times, of course, the notes for that plate will
be added 2 times.

3. SIGNALS

A student at ACS, recently learned that any signal can be transmitted as a
consecutive sequence of bits. Naturally curious, he wondered how many different signals there were
can transmit using X bits of 0 and Y bits of 1. Because a consecutive sequence of
bit of 1 can be interpreted as the beginning of a new signal, the student proposes to
analyze only 2 types:
• Type 1: the signal cannot contain 2 or more consecutive 1 bits
• Type 2: the signal cannot contain 3 or more consecutive 1 bits

4. STORE

A chain of stores has N warehouses throughout the country, numbered from 1 to N.
To facilitate product delivery, each warehouse will only receive parcels from one
single warehouse and can send parcels to zero or more warehouses. An exception
from this rule it is warehouse number 1, which will not receive parcels from any other
deposit.
A shipment of parcels is carried out in the following way: Let X be the warehouse that wants it
to ship, and x1, x2, . . . , xk warehouses to which he can send parcels in mode
directly, ordered ascending by number.
X will initially ship to x1. x1 will keep part of the parcels, and ship to
turn or the other parcels to other warehouses, following the same procedure. After
x1 has finished shipping, it will send an acknowledgment to X, after which X will continue
with the next deposit in his list, x2. The process is repeated until the last deposit from
list.
Your task is to answer Q questions of the form: "What deposit will you receive?"
parcels left from warehouse D, after E consecutive shipments?"
