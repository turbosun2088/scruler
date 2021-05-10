package main;

import javafx.event.EventHandler;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;

public class DragWin implements EventHandler<MouseEvent> {
    private Stage primaryStage;
    private double oldStageX;
    private double oldStageY;
    private double oldScreenX;
    private double oldScreenY;

    public DragWin(Stage primaryStage) {
        this.primaryStage = primaryStage;
    }

    @Override
    public void handle(MouseEvent event) {
        if (event.getEventType() == MouseEvent.MOUSE_PRESSED) {
            this.oldStageX = this.primaryStage.getX();
            this.oldStageY = this.primaryStage.getY();
            this.oldScreenX = event.getScreenX();
            this.oldScreenY = event.getScreenY();
        } else if (event.getEventType() == MouseEvent.MOUSE_DRAGGED) {
            this.primaryStage.setX(event.getScreenX() - this.oldScreenX + this.oldStageX);
            this.primaryStage.setY(event.getScreenY() - this.oldScreenY + this.oldStageY);
        }
    }
}
