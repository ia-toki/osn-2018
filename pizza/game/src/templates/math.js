export default function(v1, operator, v2) {
  switch (operator) {
    case '+':
      return v1 + v2
    case '-':
      return v1 - v2
    case '*':
      return v1 * v2
    case '/':
      return v1 / v2
    case '%':
      return v1 % v2
  }
}