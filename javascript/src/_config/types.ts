export interface Node extends Record<string, unknown> {
  children: Record<string, unknown>;
}
