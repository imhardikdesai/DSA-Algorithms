class Solve {
    constructor(word){
        this.word = word
    }
    checkPalindrome(){
        // Method 1 is just to check if word === word if reversed
        return this.word === this.reverseWord(this.word)
    }
    reverseWord(word){
        return word.split("").reverse().join("")
    }
    checkPalindrome2(){
        // Method 2 Making your life harder
        let result = true
        for (let i = 0; i < this.word.length; i++) {
            if(this.word[i] !== this.reverseWord(this.word)[i]){
                result = false
            }
        }
        return result
    }
}

//true
console.log((new Solve("level")).checkPalindrome())
// false
console.log((new Solve("abc")).checkPalindrome())

//true
console.log((new Solve("level")).checkPalindrome2())
//false
console.log((new Solve("abc")).checkPalindrome2())