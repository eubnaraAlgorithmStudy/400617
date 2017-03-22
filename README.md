# 반도체관 400617호에서 시작된..
 알고리즘 문제풀이!

## instructions
 ```bash
git pull
git add -A
git commit -m message
git push
```

## subjects

 - 레드블랙 (성민)
 - B, +트리 (현준)
 - 소팅 & 분할정복 (윤전)
 - 해싱 (유비)
 - AVL (윤전)
 - 동적프로그래밍 (동빈)
 - 그리디, 허프만 (수연)
 - 스트링 매치 (현준)
 - 집합, 비트벡터 (기영)

## STL

 - vector
 - set
 - list
 - stack, queue
 - map
 - iteration
 - string

## terminal 환경에서 PS1(prompt string 1), prompt 이름을 변경하는 법
 - https://coderwall.com/p/fasnya/add-git-branch-name-to-bash-prompt
 - ~/.bash_profile 에 다음 내용을 추가한다.(혹은 다른 로그인 스크립트에 추가해도 된다.)
 ```sh
 parse_git_branch() {
      git branch 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/ (\1)/'
 }
 export PS1="\u@\h \[\033[32m\]\w\[\033[33m\]\$(parse_git_branch)\[\033[00m\] $ "
 ```


## Learn markdown!
 - https://guides.github.com/features/mastering-markdown/
 - http://www.markdowntutorial.com/
