pipeline {
    agent any
    stages {
        stage('Build') {
            steps{
                sh 'echo "Building..."'
                sh 'chmod +x Scripts/Linux-Build.sh'
                sh 'Scripts/Linux-Build.sh'
                archiveArtifacts artifacts: 'Build/bin/*', fingerprint: true
            }
        }
        stage(‘Success’) {
            when {
                expression { doError == ‘0’ }
            }
            steps {
                sh 'echo "Deploying Doxygen"'
                sh 'chmod +x Scripts/Jenkins-Deploy-Doxygen.sh'
                sh 'Scripts/Jenkins-Deploy-Doxygen.sh JenkinsRun'
            }
        }
    }
}