//we run this loop scaled to its 'n' amount with the size of our input based on time
//O(n) - linear complexity

const data = ['A', 'B', 'C']; // length 'n'
const data2 = [1, 2, 3, 4, 5]; // length 'a'

for (let j = 0; j < data2.length; j++) {
    console.log(data2[i]);
}

for (let i = 0; i < data.length; i++) {
    console.log(data[i]);
}

//O(n + a) length loop here
//We loop thru 1st loop once and 


// this performs operations slowly at O(n^2) complexity
// very poor performance as it slows down algorithms 

for (let j = 0; j < data.length; j++) {
    for (let i = 0; i < data.length; i++) {
        console.log(data[i] + data[j])
    }
}

//this would be O(4n^2) but we only care about O(n^2) which tells us algorithm growth over time
//you could remove extra added sections

for (let j = 0; j < data.length; j++) {
    for (let i = 0; i < data.length; i++) {
        console.log(data[i] + data[j])
        console.log(data[i] + data[j])
        console.log(data[i] + data[j])
        console.log(data[i] + data[j])
    }
}


/*
FOR INSTANCE:

const data = ['A', 'B', 'C']; // length 'n'

// O(n^2)
for (let j = 0; j < data.length; j++) {
    for (let i = 0; i < data.length; i++) {
        console.log(data[i] + data[j])
    }
}

// O(n)
for (let i = 0; i < data.length; i++) {
    console.log(data[i]);
}

Would be O (n^2 + n) but we omit the 'n' because 'n^2' will 
growth way more quicker and scale much quicker

*/

//Space complexity , other than time  , uses memory as an input

const out = [];

for (let i = 0; i < data.length; i++) {
    out[i] = [];
    for (let j = 0; j < data.length; j++) {
        out[i][j] = data[i];
    }
}

//will have space complexity of 0(n^2)
//worrying about space complexity isn't as common 
//time based is where big-O notation will be used the most
