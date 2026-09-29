#include <stdio.h>

int main()
{
    double accuracy, confidence, modelScore;
    int datasetSize, role, status;

    printf("Enter accuracy (0-100): ");
    scanf("%lf", &accuracy);

    printf("Enter confidence score (0-100): ");
    scanf("%lf", &confidence);

    printf("Enter dataset size: ");
    scanf("%d", &datasetSize);

    printf("Enter user role (1=Intern, 2=Engineer, 3=Admin): ");
    scanf("%d", &role);

    printf("Enter status flags: ");
    scanf("%d", &status);

    // Calculate model score
    int dataScore;

    if (datasetSize / 1000 < 10)
        dataScore = datasetSize / 1000;
    else
        dataScore = 10;

    modelScore = (accuracy * 0.5) +
                 (confidence * 0.3) +
                 (dataScore * 2);

    printf("\nModel Score: %.2f\n", modelScore);

    // Deployment decision
    if (status & 8)
        printf("Rejected: model deprecated\n");

    else if (!(status & 1))
        printf("Rejected: not trained\n");

    else if (!(status & 2))
        printf("Rejected: not validated\n");

    else if (!(status & 4))
        printf("Pending: awaiting approval\n");

    else if (accuracy < 70 || confidence < 60)
        printf("Rejected: performance too low\n");

    else if (datasetSize < 5000)
        printf("Rejected: dataset too small\n");

    else if (role == 1)
        printf("Denied: interns cannot deploy\n");

    else if (role == 2 && modelScore < 80)
        printf("Denied: engineer needs higher score\n");

    else
        printf("Approved for deployment\n");

    // Compare model score with average
    double average = (accuracy + confidence) / 2;

    if (modelScore > average)
        printf("Model score is above the average of accuracy and confidence\n");
    else
        printf("Model score is not above the average of accuracy and confidence\n");

    // Print sizes
    printf("\nSize of variables:\n");
    printf("accuracy: %zu bytes\n", sizeof(accuracy));
    printf("confidence: %zu bytes\n", sizeof(confidence));
    printf("datasetSize: %zu bytes\n", sizeof(datasetSize));
    printf("role: %zu bytes\n", sizeof(role));
    printf("status: %zu bytes\n", sizeof(status));
    printf("modelScore: %zu bytes\n", sizeof(modelScore));

    return 0;
}