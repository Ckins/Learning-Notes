## init and bind to a github repo
```shell
cd ~/repo
git init
git config user.name "example"
git config user.email "example@mail.com"
git add --all
git commit -m "init"
git remote add origin git@github.com:Ckins/example.git
git push -u origin master
```
## check status
git status

## remove changes in a commit
git reset HEAD example.txt

## branch feature
git checkout master
git branch feature-xxx
