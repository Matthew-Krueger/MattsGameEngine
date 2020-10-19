pipeline {
    agent any
    stages {
        stage('Build') {
            sh 'echo "Building..."'
            sh 'chmod +x Scripts/Linux-Build.sh'
            sh 'Scripts/Linux-Build.sh'
            archiveArtifacts artifacts: 'Build/bin/*', fingerprint: true
        }
    }

}