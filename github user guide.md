### gitignore
#### ignore files checked in
first,`$ git rm --cached FILENAME`,then, add file path to .gitignore

### unserstanding the github flow
#### create a flow
branch is the core concept of github,since anything in the `master` is deployable,so you can experiment your features on the branch,which should have a **descriptive name**
#### add commits
commits make it clear for others to track your changes,every commit is a seperate unit of change,along with commit messages,you can work in progress.
#### open a pull request
a pull request initiate a discussion about your commits.a pull request may happen at any point during your development process.you can use @mention system to share or ask feedback from any team member.
#### discuss and review your code
during the process,you may receive comments about your code,you can continue to change your code and push up to your branch,github will show your new commits or new feedbacks.
#### deploy to verify
you may deploy your code to verify if it work well in production,for example,a provisioned testing environment.if some thing went wrong,you can roll back or you can continue to merge your code into the master.<br>
by associating **issues** with pull requests, it makes clearly what bug was fixed or what features was implemented,all the development process is tackable now.<br>
**reference:https://guides.github.com/introduction/flow/**
