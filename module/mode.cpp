#include "mode.h"

while (1) {
    sensorBrightness = getbright();
    userBrightness = modifyuserbright();  //�������׿� ���� ����

    if (brightModeSwitch) { // ��� ��尡 Ȱ��ȭ�Ǿ� ���� ��
        if (userBrightness >= sensorBrightness) {
            if (ismax()) {
                break; // ���� ����
            }
            else {
                if (motorState != MOTOR_OPENING) {
                    openmax(); // ���� ����
                    motorState = MOTOR_OPENING;
                }
            }
        }
        else {
            if (ismin()) {
                break; // 
            }
            else {
                if (motorState != MOTOR_CLOSING) {
                    closemin(); // ���� �ݱ�  close min �̻���
                    motorState = MOTOR_CLOSING;
                }
            }
        }
    }

    updateMotorState(); // ������ ���¸� �ֱ������� ������Ʈ
}
