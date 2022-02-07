function getList(base: number, number: number): number[] {
  if ((base | 0) !== base) {
    throw new Error("Invalid base: base must be a integer");
  } else if (base <= 0) {
    throw new Error("Invalid base: base must be positive");
  }

  if ((number | 0) !== number) {
    throw new Error("Invalid number: number must be a integer");
  } else if (number < 0 || number >= base) {
    throw new Error("Invalid number: number must in range 0..base");
  }

  const result: number[] = [];
  for (let i = 0; i < base; i++) {
    const current = (i ? result[i - 1] : 1) * number % base;
    if (result.includes(current)) break;
    result.push(current);
  }
  return result;
}

function getLists(base: number): number[][] {
  return Array.from(new Array(base)).map((_, i) => getList(base, i));
}

console.log(getLists(10));
