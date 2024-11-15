function solution(s) {

  let str1 = [-1];

  for (let i = 1; i < s.length; i++) {
    let found = false;
    for (let j = i - 1; j >= 0; j--) {
      if (s[i] === s[j]) {
        str1.push(i - j);
        found = true;
        break;
      }
    }

    if (!found) {
      str1.push(-1);
    }
  }
  return str1;
}


