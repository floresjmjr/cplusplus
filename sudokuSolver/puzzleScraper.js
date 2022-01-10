const axios = require('axios');

axios.get("https://sudoku.com.au/").then((response)=>{
  let string = (response.data).match(/<tbody>(.*)<\/tbody>/);
  console.log(string)
})

