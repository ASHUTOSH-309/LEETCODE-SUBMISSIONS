/**
 * @param {string} sentence1
 * @param {string} sentence2
 * @return {boolean}
 */


//Logic:
/* 

1. Check if the trailing and the leading characters are matching, if it is so, then 
2. Check whether the smaller string is a substring of the larger one 

Got me a Tle haha 130 on 138


Failed on 

s1="qbaVXO Msgr aEWD v ekcb"
s2="Msgr aEWD ekcb"

output should have been false as two different strings are reqiured to be inserted, 

*/
function isContainingSmallString(smallWords, largeWords) {

    let largeSet = new Set(largeWords);
    return smallWords.every(word => largeSet.has(word));
}


var areSentencesSimilar = function (sentence1, sentence2) {

    let s1Array = sentence1.split(" ");
    let s2Array = sentence2.split(" ");

    if ((s1Array[0] == s2Array[0]) || (s1Array[s1Array.length - 1] == s2Array[s2Array.length - 1])) {


        if (s1Array.length < s2Array.length) {
            return isContainingSmallString(s1Array, s2Array)
        }
        else {
            return isContainingSmallString(s2Array, s1Array)
        }
    }

    return false;


};