/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
const combinationSum = (candidates, target) = {
  let ans = [[[]]]
  for(let i = 0; i < candidates.length; i += 1) {
      for(let j = candidates[i]; j <= target; j += 1) {
          if(ans[j-candidates[i]] !== undefined && ans[j-candidates[i]].length) {
              for(let k = 0; k < ans[j-candidates[i]].length; k += 1) {
                  let tmp = [...ans[j-candidates[i]][k]]
                  tmp.push(candidates[i])
                  if(ans[j] === undefined) ans[j] = []
                  ans[j].push(tmp)
              }
          }
      }
  }
  return ans[target] || []
};